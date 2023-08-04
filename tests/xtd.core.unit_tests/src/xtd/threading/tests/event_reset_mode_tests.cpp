#include <xtd/threading/event_reset_mode.h>
#include <xtd/xtd.tunit>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(ƒ_tests) {
  public:
    void test_method_(auto_reset) {
      assert::are_equal(0, enum_object<>::to_int32(event_reset_mode::auto_reset), csf_);
      assert::are_equal("auto_reset", enum_object<>::to_string(event_reset_mode::auto_reset), csf_);
      assert::are_equal(event_reset_mode::auto_reset, enum_object<>::parse<event_reset_mode>("auto_reset"), csf_);
    }
    
    void test_method_(manual_reset) {
      assert::are_equal(1, enum_object<>::to_int32(event_reset_mode::manual_reset), csf_);
      assert::are_equal("manual_reset", enum_object<>::to_string(event_reset_mode::manual_reset), csf_);
      assert::are_equal(event_reset_mode::manual_reset, enum_object<>::parse<event_reset_mode>("manual_reset"), csf_);
    }
  };
}

