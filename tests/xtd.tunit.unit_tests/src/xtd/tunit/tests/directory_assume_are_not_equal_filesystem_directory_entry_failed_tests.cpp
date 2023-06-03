#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

#if defined(__cpp_lib_filesystem)
namespace xtd::tunit::tests {
  class test_class_(directory_assume_are_not_equal_filesystem_directory_entry_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::filesystem::directory_entry d1(std::filesystem::path(xtd::environment::get_folder_path(xtd::environment::special_folder::common_application_data).c_str()));
      std::filesystem::directory_entry d2(std::filesystem::path(xtd::environment::get_folder_path(xtd::environment::special_folder::common_application_data).c_str()));
      xtd::tunit::directory_assume::are_not_equal(d1, d2);
    }
  };
}

void test_(directory_assume_are_not_equal_filesystem_directory_entry_failed_tests, test_output) {
  auto [output, result] = run_test_("directory_assume_are_not_equal_filesystem_directory_entry_failed_tests.*");
  assert_value_(xtd::ustring::format("Start 1 test from 1 test case\n"
    "  ABORTED directory_assume_are_not_equal_filesystem_directory_entry_failed_tests.test_case_failed\n"
    "    Test aborted\n"
    "End 1 test from 1 test case ran.\n", xtd::environment::get_folder_path(xtd::environment::special_folder::common_application_data).quoted()), output);
}

void test_(directory_assume_are_not_equal_filesystem_directory_entry_failed_tests, test_result) {
  auto [output, result] = run_test_("directory_assume_are_not_equal_filesystem_directory_entry_failed_tests.*");
  assert_value_(0, result);
}
#endif
