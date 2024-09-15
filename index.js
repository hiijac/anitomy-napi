const binding = require("pkg-prebuilds")(
  __dirname,
  require("./binding-options")
);

module.exports = binding;
