/// @file
/// @brief Contains xtd::tunit::test_initialize_attribute class.
#pragma once
#include "test.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    class test_initialize_attribute {
    public:
      template<typename TestClass>
      test_initialize_attribute(const std::string& name, TestClass& test_class, void (*method)()) noexcept :  test_initialize_attribute(name, test_class, method, xtd::tunit::line_info()) {}
      
      template<typename TestClass>
      test_initialize_attribute(const std::string& name, TestClass& test_class, void (*method)(), const xtd::tunit::line_info& caller) noexcept {test_class.add_test_initialize({name, method, caller});}
    };
  }
}

#define test_initialize_(method_name) \
  __##method_name##_unused() = delete; \
  class __test_initialize_attribute : public xtd::tunit::test_initialize_attribute { \
  public:\
    template<typename test_class> __test_initialize_attribute(test_class& test) : test_initialize_attribute(#method_name, test, &test_class::method_name, {__func__, __FILE__, __LINE__}) {} \
  } __test_initialize_attribute {*this}; \
  static void method_name()

