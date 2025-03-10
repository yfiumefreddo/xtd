/// @file
/// @brief Contains xtd::platform_not_supported_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "not_supported_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when a feature does not run on a particular platform.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  /// @par Examples
  /// The following example demonstrates how to throw and catch an platform_not_supported_exception.
  /// @include platform_not_supported_exception.cpp
  class platform_not_supported_exception : public not_supported_exception {
  public:
    /// @name Constructors
    
    /// @{
    /// @brief Create a new instance of class platform_not_supported_exception
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit platform_not_supported_exception(const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : not_supported_exception(default_message(), info) {}
    /// @brief Create a new instance of class platform_not_supported_exception
    /// @param message Message string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit platform_not_supported_exception(const xtd::ustring& message, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : not_supported_exception(message, info) {}
    /// @brief Create a new instance of class platform_not_supported_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit platform_not_supported_exception(const xtd::ustring& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : not_supported_exception(message, error, info) {}
    /// @brief Create a new instance of class platform_not_supported_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit platform_not_supported_exception(const xtd::ustring& message, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : not_supported_exception(message, help_link, info) {}
    /// @brief Create a new instance of class platform_not_supported_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit platform_not_supported_exception(const xtd::ustring& message, const std::error_code& error, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : not_supported_exception(message, error, help_link, info) {}
    /// @brief Create a new instance of class platform_not_supported_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit platform_not_supported_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : not_supported_exception(default_message(), inner_exception, info) {}
    /// @brief Create a new instance of class platform_not_supported_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit platform_not_supported_exception(const xtd::ustring& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : not_supported_exception(message, inner_exception, info) {}
    /// @brief Create a new instance of class platform_not_supported_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit platform_not_supported_exception(const xtd::ustring& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : not_supported_exception(message, inner_exception, error, info) {}
    /// @brief Create a new instance of class platform_not_supported_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit platform_not_supported_exception(const xtd::ustring& message, const std::exception& inner_exception, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : not_supported_exception(message, inner_exception, help_link, info) {}
    /// @brief Create a new instance of class platform_not_supported_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit platform_not_supported_exception(const xtd::ustring& message, const std::exception& inner_exception, const std::error_code& error, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : not_supported_exception(message, inner_exception, error, help_link, info) {}
    /// @}
    
    /// @cond
    platform_not_supported_exception(const platform_not_supported_exception&) = default;
    platform_not_supported_exception& operator =(const platform_not_supported_exception&) = default;
    /// @endcond
    
  private:
    const char* default_message() const noexcept {return "Operation is not supported on this platform."_t;}
  };
}

/// @brief Helper on xtd::platform_not_supported_exception to call it with current stack frame information.
/// @par Library
/// xtd.core
/// @ingroup xtd_core exceptions
/// @remarks Is equivalent to xtd::platform_not_supported_exception {{any argument}, csf_}
/// @code
/// void my_func() {
///   if (invalid_info) throw platform_not_supported_exception_(); // same as : throw platform_not_supported_exception {csf_};
///   if (invalid_value) throw platform_not_supported_exception_("Bad value"); // same as : throw platform_not_supported_exception {"Bad value", csf_};
///   ...
/// }
/// @endcode
#define platform_not_supported_exception_(...) platform_not_supported_exception(add_csf_(__VA_ARGS__))
