#include <morph/client.h>

#include <rice/Array.hpp>
#include <rice/Class.hpp>
#include <rice/Constructor.hpp>
#include <rice/Hash.hpp>
#include <rice/Module.hpp>

using namespace Rice;

extern "C"
void Init_ext() {
  Module rb_mMorph = define_module("Morph");

  define_class_under<morph::Client>(rb_mMorph, "Client")
    .define_constructor(Constructor<morph::Client>())
    .define_method("keygen", &morph::Client::keygen)
    .define_method("set", &morph::Client::set)
    .define_method("flushall", &morph::Client::flushall)
    .define_method("dbsize", &morph::Client::dbsize)
    .define_method("info", &morph::Client::info)
    .define_method(
      "get",
      *[](morph::Client& self, const std::string& key) {
        auto value = self.get(key);
        // TODO fix in C++ library
        return value.empty() ? Nil : String(value.c_str());
      })
    .define_method(
      "keys",
      *[](morph::Client& self, const std::string& pattern) {
        auto keys = self.keys(pattern);
        Array res;
        for (auto &k : keys) {
          // TODO fix in C++ library
          res.push(k.c_str());
        }
        return res;
      });
}
