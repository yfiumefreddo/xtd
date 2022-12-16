#include "../../../include/xtd/tunit/test.h"
#include "../../../include/xtd/tunit/unit_test.h"
#include <exception>

using namespace xtd;
using namespace xtd::tunit;

test* test::current_test_ = nullptr;
const test_class* test::current_test_class_ = nullptr;
const unit_test* test::current_unit_test_ = nullptr;
intptr test::__internal_tunit_unit_tests_mode__ = reinterpret_cast<intptr>("");

test::test(const std::string& name, const std::function<void()>& method, const xtd::diagnostics::stack_frame& stack_frame) noexcept : test(name, method, false, stack_frame) {
}

test::test(const std::string& name, const std::function<void()>& method, bool ignore, const xtd::diagnostics::stack_frame& stack_frame) noexcept : stack_frame_(stack_frame), method_(method), name_(name), status_(ignore ? test_status::ignored : test_status::not_started) {
}

bool test::aborted() const noexcept {
  return status_ == test_status::aborted;
}

const std::string& test::actual() const noexcept {
  return actual_;
}

std::chrono::milliseconds test::elapsed_time() const noexcept {
  using namespace std::chrono_literals;
  if (start_time_.ticks() == 0ms && end_time_point.ticks() == 0ms) return 0ms;
  if (end_time_point.ticks() == 0ms) return std::chrono::duration_cast<std::chrono::milliseconds>((date_time::now() - start_time_).ticks());
  return std::chrono::duration_cast<std::chrono::milliseconds>((end_time_point - start_time_).ticks());
}

const std::string& test::expect() const noexcept {
  return expect_;
}

bool test::failed() const noexcept {
  return status_ == test_status::failed;
}

bool test::ignored() const noexcept {
  return status_ == test_status::ignored;
}

bool test::not_started() const noexcept {
  return status_ == test_status::not_started;
}

bool test::succeed() const noexcept {
  return status_ == test_status::succeed;
}

const xtd::diagnostics::stack_frame test::stack_frame() const noexcept {
  return stack_frame_;
}

const xtd::date_time& test::start_time() const noexcept {
  return start_time_;
}

std::function<void()> test::method() const noexcept {
  return method_;
}

const std::string& test::message() const noexcept {
  return message_;
}

const std::string& test::name() const noexcept {
  return name_;
}

const std::string& test::user_message() const noexcept {
  return user_message_;
}

test& test::current_test() {
  return *current_test_;
}

const test_class& test::current_test_class() {
  return *current_test_class_;
}

const unit_test& test::current_unit_test() {
  return *current_unit_test_;
}

bool test::has_current_test() {
  return current_test_ != nullptr;
}

bool test::has_current_test_class() {
  return current_test_class_ != nullptr;
}

bool test::has_current_unit_test() {
  return current_unit_test_ != nullptr;
}

void test::run(const unit_test& unit_test, const xtd::tunit::test_class& test_class) {
  current_test_ = this;
  current_test_class_ = &test_class;
  current_unit_test_ = &unit_test;
  
  if (ignored() && settings::default_settings().also_run_ignored_tests()) status_ = test_status::not_started;
  
  if ((std::string(reinterpret_cast<const char*>(__internal_tunit_unit_tests_mode__)) == "internal_tests" || settings::default_settings().repeat_test() != 1) && (aborted() || failed() || succeed())) status_ = test_status::not_started;
  
  if (settings::default_settings().is_match_test_name(test_class.name(), name())) {
    if (ignored()) {
      try {
        assert::ignore();
      } catch (const xtd::tunit::ignore_error&) {
        unit_test.event_listener_->on_test_ignored(xtd::tunit::test_event_args(*this, test_class, unit_test));
      }
    } else if (not_started()) {
      unit_test.event_listener_->on_test_initialize_start(xtd::tunit::test_event_args(*this, test_class, unit_test));
      if (test_class.test_initialize().method() != nullptr)
        test_class.test_initialize().method()();
      unit_test.event_listener_->on_test_initialize_end(xtd::tunit::test_event_args(*this, test_class, unit_test));
      
      unit_test.event_listener_->on_test_start(xtd::tunit::test_event_args(*this, test_class, unit_test));
      try {
        start_time_ = date_time::now();
        method()();
        end_time_point = date_time::now();
        if (not_started()) status_ = test_status::succeed;
        if (succeed())
          unit_test.event_listener_->on_test_succeed(xtd::tunit::test_event_args(*this, test_class, unit_test));
        /*
        else {
          xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
          unit_test.event_listener_->on_test_failed(xtd::tunit::test_event_args(*this, test_class, unit_test));
        }
         */
      } catch (const xtd::tunit::abort_error&) {
        unit_test.event_listener_->on_test_aborted(xtd::tunit::test_event_args(*this, test_class, unit_test));
      } catch (const xtd::tunit::assert_error&) {
        xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
        unit_test.event_listener_->on_test_failed(xtd::tunit::test_event_args(*this, test_class, unit_test));
      } catch (const xtd::tunit::ignore_error&) {
        unit_test.event_listener_->on_test_ignored(xtd::tunit::test_event_args(*this, test_class, unit_test));
      } catch (const std::exception& e) {
        xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
        xtd::tunit::test::current_test().message_ = "Exception <" + __tunit_demangle(typeid(e).name()) + "> throws" + " (" + e.what() + ")";
        xtd::tunit::test::current_test().status_ = test::test_status::failed;
        unit_test.event_listener_->on_test_failed(xtd::tunit::test_event_args(*this, test_class, unit_test));
      } catch (...) {
        xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
        xtd::tunit::test::current_test().message_ = "Exception <unknown> throws";
        xtd::tunit::test::current_test().status_ = test::test_status::failed;
        unit_test.event_listener_->on_test_failed(xtd::tunit::test_event_args(*this, test_class, unit_test));
      }
      
      unit_test.event_listener_->on_test_cleanup_start(xtd::tunit::test_event_args(*this, test_class, unit_test));
      if (test_class.test_cleanup().method() != nullptr)
        test_class.test_cleanup().method()();
      unit_test.event_listener_->on_test_cleanup_end(xtd::tunit::test_event_args(*this, test_class, unit_test));
      
      unit_test.event_listener_->on_test_end(xtd::tunit::test_event_args(*this, test_class, unit_test));
    }
  }
}

