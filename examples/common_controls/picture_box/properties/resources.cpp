#pragma region xtd generated code
// This code was generated by CMake script.
//
// Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.

#include <exception>
#include "resources.hpp"

const xtd::drawing::bitmap& picture_box::properties::resources::logo() {
  static xtd::drawing::bitmap bitmap(xtd::io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), "..", "resources", "logo.png"));
  return bitmap;
}

#pragma endregion
