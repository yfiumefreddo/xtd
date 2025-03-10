#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto a = vector {1, 2, 3, 4};
      collection_valid::are_not_equivalent({1, 2, 3, 5}, a);
    }
    
    void test_method_(test_case_failed) {
      auto a = vector {1, 2, 3, 4};
      collection_valid::are_not_equivalent({4, 3, 2, 1}, a);
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
//   FAILED  test.test_case_failed (0 ms total)
//     Expected: not equivalent < 4, 3, 2, 1 >
//     But was:  < 1, 2, 3, 4 >
//     Stack Trace: in |---OMITTED---|/collection_valid_are_not_equivalent.cpp:13
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
