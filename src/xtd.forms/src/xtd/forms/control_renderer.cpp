#include "../../../include/xtd/forms/control_renderer.h"
#include "../../../include/xtd/forms/style_sheets/button.h"
#include "../../../include/xtd/forms/style_sheets/pseudo_state.h"
#include "../../../include/xtd/forms/style_sheets/style_sheet.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::forms::visual_styles;

void control_renderer::draw_control(graphics& graphics, const rectangle& bounds) {
  draw_control(graphics, bounds, control_state::normal, nullopt);
}

void control_renderer::draw_control(graphics& graphics, const rectangle& bounds, control_state control_state) {
  draw_control(graphics, bounds, control_state, nullopt);
}

void control_renderer::draw_control(graphics& graphics, const rectangle& bounds, control_state control_state, const optional<color>& back_color) {
  draw_control(style_sheet::current_style_sheet(), graphics, bounds, control_state, back_color);
}

void control_renderer::draw_control(const style_sheets::style_sheet& style_sheet, graphics& graphics, const rectangle& bounds, control_state state, const optional<color>& back_color) {
  style_sheets::control current_control_style_sheet;
  switch (state) {
    case control_state::normal: current_control_style_sheet = style_sheet.control(style_sheets::pseudo_state::standard); break;
    case control_state::hot: current_control_style_sheet = style_sheet.control(style_sheets::pseudo_state::standard | pseudo_state::hover); break;
    case control_state::pressed: current_control_style_sheet = style_sheet.control(style_sheets::pseudo_state::standard | pseudo_state::pressed); break;
    case control_state::disabled: current_control_style_sheet = style_sheet.control(style_sheets::pseudo_state::standard | pseudo_state::disabled); break;
  }
  
  if (back_color) current_control_style_sheet.background_color(back_color.value());

  box_renderer::draw_box(graphics, bounds, current_control_style_sheet);
}
