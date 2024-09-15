#include <anitomy.hpp>
#include <napi.h>
#include <iostream>

using namespace anitomy;

class AniWrap : public Napi::Addon<AniWrap> {
  public:
    AniWrap(Napi::Env env, Napi::Object exports) {
        DefineAddon(
            exports,
            {
                InstanceMethod("parse", &AniWrap::parse),
            }
        );
    }

  private:
    Napi::Value parse(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        std::string input = info[0].As<Napi::String>().Utf8Value();

        auto elements = anitomy::parse(input);

        Napi::Object obj = Napi::Object::New(env);
        for (size_t i = 0; i < elements.size(); i++) {
            auto elem = elements[i];
            obj.Set(elementKindToString(elem.kind), Napi::String::New(env, elem.value));
        }
        return obj;
    }

    std::string elementKindToString(ElementKind kind) {
        switch (kind) {
        case ElementKind::AudioTerm:
            return "AudioTerm";
        case ElementKind::DeviceCompatibility:
            return "DeviceCompatibility";
        case ElementKind::Episode:
            return "Episode";
        case ElementKind::EpisodeTitle:
            return "EpisodeTitle";
        case ElementKind::FileChecksum:
            return "FileChecksum";
        case ElementKind::FileExtension:
            return "FileExtension";
        case ElementKind::Language:
            return "Language";
        case ElementKind::Other:
            return "Other";
        case ElementKind::ReleaseGroup:
            return "ReleaseGroup";
        case ElementKind::ReleaseInformation:
            return "ReleaseInformation";
        case ElementKind::ReleaseVersion:
            return "ReleaseVersion";
        case ElementKind::Season:
            return "Season";
        case ElementKind::Source:
            return "Source";
        case ElementKind::Subtitles:
            return "Subtitles";
        case ElementKind::Title:
            return "Title";
        case ElementKind::Type:
            return "Type";
        case ElementKind::VideoResolution:
            return "VideoResolution";
        case ElementKind::VideoTerm:
            return "VideoTerm";
        case ElementKind::Volume:
            return "Volume";
        case ElementKind::Year:
            return "Year";
        default:
            return "Unknown";
        }
    }
};

NODE_API_ADDON(AniWrap)