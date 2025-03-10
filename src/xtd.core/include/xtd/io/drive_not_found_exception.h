/// @file
/// @brief Contains xtd::io::drive_not_found_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "io_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief The exception that is thrown when trying to access a drive or share that is not available.
    /// @code
    /// class drive_not_found_exception : public xtd::io::io_exception
    /// @endcode
    /// @par Inheritance
    /// xtd::io::io_exception → xtd::io::drive_not_found_exception
    /// @par Header
    /// @code #include <xtd/io/drive_not_found_exception> @endcode
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core exceptions
    /// @par Examples
    /// The following example demonstrates how to throw and catch an drive_not_found_exception.
    /// @include drive_not_found_exception.cpp
    class drive_not_found_exception : public xtd::io::io_exception {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      explicit drive_not_found_exception(const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : io_exception(default_message(), info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit drive_not_found_exception(const xtd::ustring& message, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : io_exception(message, info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit drive_not_found_exception(const xtd::ustring& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : io_exception(message, error, info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit drive_not_found_exception(const xtd::ustring& message, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : io_exception(message, help_link, info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      explicit drive_not_found_exception(const xtd::ustring& message, const std::error_code& error, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : io_exception(message, error, help_link, info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      explicit drive_not_found_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : io_exception(default_message(), inner_exception, info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit drive_not_found_exception(const xtd::ustring& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : io_exception(message, inner_exception, info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit drive_not_found_exception(const xtd::ustring& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : io_exception(message, inner_exception, error, info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit drive_not_found_exception(const xtd::ustring& message, const std::exception& inner_exception, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : io_exception(message, inner_exception, help_link, info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit drive_not_found_exception(const xtd::ustring& message, const std::exception& inner_exception, const std::error_code& error, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : io_exception(message, inner_exception, error, help_link, info) {}
      /// @}
      
      /// @cond
      drive_not_found_exception(const drive_not_found_exception&) = default;
      drive_not_found_exception& operator =(const drive_not_found_exception&) = default;
      /// @endcond
      
    private:
      const char* default_message() const noexcept {return "Attempted to access a drive that is not available."_t;}
    };
  }
}

/// @brief Helper on xtd::io::drive_not_found_exception to call it with current stack frame information.
/// @par Header
/// @code #include <xtd/io/drive_not_found_exception> @endcode
/// @par Library
/// xtd.core
/// @ingroup xtd_core exceptions
/// @remarks Is equivalent to xtd::io::drive_not_found_exception {{any argument}, csf_}
/// @code
/// void my_func() {
///   if (invalid_info) throw drive_not_found_exception_(); // same as : throw drive_not_found_exception {csf_};
///   if (invalid_value) throw drive_not_found_exception_("Bad value"); // same as : throw drive_not_found_exception {"Bad value", csf_};
///   ...
/// }
/// @endcode
#define drive_not_found_exception_(...) drive_not_found_exception(add_csf_(__VA_ARGS__))
