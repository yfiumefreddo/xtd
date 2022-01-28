/// @file
/// @brief Contains xtd::forms::style_sheets::style_sheet class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <map>
#include <xtd/iequatable.h>
#include <xtd/object.h>
#include "../../forms_export.h"
#include "button_selector.h"
#include "form_selector.h"
#include "label_selector.h"
#include "system_colors_selector.h"
#include "theme_selector.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The xtd::forms::style_sheets::style_sheet allows you to specify an xtd style sheet.
      /// @code
      /// class forms_export_ style_sheet : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::style_sheet
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks This class is used by xtd::forms::style_sheets::box_data.
      class forms_export_ style_sheet : public xtd::iequatable<style_sheet>, public xtd::object {
      public:
        /// @name Constructors
        
        /// @brief Initialize a new xtd::forms::style_sheets::style_sheet instance.
        style_sheet() = default;
        /// @brief Initialize a new xtd::forms::style_sheets::style_sheet instance from specified css forrmated text.
        explicit style_sheet(const xtd::ustring& text);

        /// @cond
        style_sheet(const style_sheet&) = default;
        style_sheet(style_sheet&&) = default;
        style_sheet& operator=(const style_sheet&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        const button_selector& button() const noexcept;

        const control_selector& control() const noexcept;

        const form_selector& form() const noexcept;

        const label_selector& label() const noexcept;

        static const std::map<xtd::ustring, style_sheet> style_sheets() noexcept;

        const system_colors_selector& system_colors()const noexcept;

        const theme_selector& theme() const noexcept;
        /// @}

        /// @name Methods
        
        /// @{
        bool equals(const object& other) const noexcept override;
        bool equals(const style_sheet& other) const noexcept override;
        /// @}
        
      private:
        static void initilize();
        
        button_selector button_;
        control_selector control_;
        form_selector form_;
        label_selector label_;
        static std::map<ustring, style_sheet> style_sheets_;
        system_colors_selector system_colors_;
        theme_selector theme_;
      };
    }
  }
}
