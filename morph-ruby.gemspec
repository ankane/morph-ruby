require_relative "lib/morph/version"

Gem::Specification.new do |spec|
  spec.name          = "morph-ruby"
  spec.version       = Morph::VERSION
  spec.summary       = "Morph client for Ruby"
  spec.homepage      = "https://github.com/ankane/morph-ruby"
  spec.license       = "Apache-2.0"

  spec.author        = "Andrew Kane"
  spec.email         = "andrew@ankane.org"

  spec.files         = Dir["*.{md,txt}", "{ext,lib}/**/*"]
  spec.require_path  = "lib"
  spec.extensions    = ["ext/morph/extconf.rb"]

  spec.required_ruby_version = ">= 3.2"

  spec.add_dependency "rice", ">= 4.3.3"
end
