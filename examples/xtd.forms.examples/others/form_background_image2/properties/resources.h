#pragma region xtd generated code
// This code was generated by CMake script.
//
// Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.

#pragma once

#include <xtd/not_implemented_exception.h>
#include <xtd/xtd>

namespace form_background_image2::properties {
  /// @brief A strongly-typed resource class, for looking up localized strings, etc.
  /// @details This class was auto-generated by CMake script. To add or remove a member, edit your CMakeList.txt or properties/resources.cmake file then rerun cmake tools.
  /// @remarks See <a href=https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/resources>Resources</a> for more informations.
  class resources final static_ {
  public:
    /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
    static const xtd::drawing::bitmap& background() {
      static xtd::drawing::bitmap bitmap(xtd::io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), "..", "Resources", "background.png"));
      return bitmap;
    }

  };
}

#pragma endregion
