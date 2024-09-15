cmake_minimum_required(VERSION 3.16)
cmake_policy(SET CMP0091 NEW)
cmake_policy(SET CMP0042 NEW)

set(NODE_ADDON_API_DIR "${CMAKE_CURRENT_LIST_DIR}/node_modules/node-addon-api")
set(NODE_API_HEADERS_DIR "${CMAKE_CURRENT_LIST_DIR}/node_modules/node-api-headers/include")

project(anitomy_napi)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_definitions(
	-DNAPI_VERSION=9
    -DV8_COMPRESS_POINTERS
    -DV8_REVERSE_JSARGS
    -DV8_COMPRESS_POINTERS_IN_ISOLATE_CAGE
)
include_directories(${NODE_API_HEADERS_DIR} ${NODE_ADDON_API_DIR} ${CMAKE_JS_INC} ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(
	${PROJECT_NAME} 
	SHARED ${CMAKE_JS_SRC}
	src/main.cpp
)

target_sources(
	${PROJECT_NAME}
	PUBLIC src/main.cpp
	PRIVATE 
		FILE_SET HEADERS
        		BASE_DIRS ${CMAKE_SOURCE_DIR}/anitomy/include
        		FILES ${CMAKE_SOURCE_DIR}/anitomy/include/anitomy.hpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
target_link_libraries(
	${PROJECT_NAME} 
	PRIVATE ${CMAKE_JS_LIB}
)


if(MSVC AND CMAKE_JS_NODELIB_DEF AND CMAKE_JS_NODELIB_TARGET)
  # Generate node.lib
  execute_process(COMMAND ${CMAKE_AR} /def:${CMAKE_JS_NODELIB_DEF} /out:${CMAKE_JS_NODELIB_TARGET} ${CMAKE_STATIC_LINKER_FLAGS})
endif()