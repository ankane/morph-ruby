#include <string>

#include <morph/client.h>

#include <rice/rice.hpp>
#include <rice/stl.hpp>

extern "C"
void Init_ext() {
  Rice::Module rb_mMorph = Rice::define_module("Morph");

  Rice::define_class_under<morph::Client>(rb_mMorph, "Client")
    .define_constructor(Rice::Constructor<morph::Client>())
    .define_method("keygen", &morph::Client::keygen)
    .define_method("set", &morph::Client::set)
    .define_method("flushall", &morph::Client::flushall)
    .define_method("dbsize", &morph::Client::dbsize)
    .define_method("info", &morph::Client::info)
    .define_method("get", &morph::Client::get)
    .define_method(
      "keys",
      *[](morph::Client& self, const std::string& pattern) {
        auto keys = self.keys(pattern);
        Rice::Array res;
        for (auto &k : keys) {
          res.push(k);
        }
        return res;
      });
}
