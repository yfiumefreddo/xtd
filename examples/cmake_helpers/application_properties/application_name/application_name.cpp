#include <xtd/xtd.forms>

using namespace xtd::forms;

int main() {
  auto main_form = control::create<form>("Application name");
  application::run(*main_form);
}
