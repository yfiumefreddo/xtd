#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/process.h>
#include <xtd/native/process_creation_flags.h>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <cstdlib>
#include <Windows.h>

using namespace xtd::native;

namespace {
  std::string shell_execute() {
    return "explorer ";
  }
}

intptr_t process::create(const std::string& command_line, int32_t process_creation_flags) {
  auto line_args = native::win32::strings::split(command_line, {' '});
  auto is_executable = line_args.size() && (native::win32::strings::ends_with(line_args[0], ".exe") || native::win32::strings::ends_with(line_args[0], ".com") || native::win32::strings::ends_with(line_args[0], ".bat") || native::win32::strings::ends_with(line_args[0], ".cmd"));

  STARTUPINFO startup_info {};
  startup_info.cb = sizeof(STARTUPINFO);
  PROCESS_INFORMATION process_information;
  CreateProcessA(nullptr, const_cast<LPSTR>(((process_creation_flags & USE_SHELL_EXECUTE_PROCESS) == USE_SHELL_EXECUTE_PROCESS && !is_executable ? shell_execute() + command_line : command_line).c_str()), nullptr, nullptr, true, process_creation_flags, nullptr, nullptr, &startup_info, &process_information);
  return reinterpret_cast<intptr_t>(process_information.hProcess);
}

bool process::kill(intptr_t handle) {
  if (handle == 0) return false;
  return TerminateProcess(reinterpret_cast<HANDLE>(handle), static_cast<uint32_t>(-1)) != 0;
}

bool process::wait(intptr_t process, int32_t& exit_code) {
  if (process == 0) return false;
  bool result = WaitForSingleObject(reinterpret_cast<HANDLE>(process), static_cast<DWORD>(-1)) == 0;
  if (result) GetExitCodeProcess(reinterpret_cast<HANDLE>(process), reinterpret_cast<LPDWORD>(&exit_code));
  return result;
}
