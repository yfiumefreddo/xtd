#include <xtd/xtd.tunit>

using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto fn = path::get_temp_file_name();
      file_assume::exists(fn);
      file::remove(fn);
    }
    
    void test_method_(test_case_failed) {
      auto fn = path::get_temp_file_name();
      file::remove(fn);
      file_assume::exists(fn);
    }
  };
}

auto main()->int {
  return console_unit_test().run();
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED test.test_case_succeed (0 ms total)
//   ABORTED test.test_case_failed (0 ms total)
//     Test aborted
//     Expected: file exists
//     But was:  "/var/folders/xg/2fvdl7v939g9kbp8xn1dpgg00000gn/T/tmp491024a4.tmp"
//     Stack Trace: in |---OMITTED---|/file_assume_exists.cpp:15
//
// Test results:
//   SUCCEED 1 test.
//   ABORTED 1 test.
// End 2 tests from 1 test case ran. (0 ms total)
