#pragma once

#include <filesystem>
#include <optional>
#include <string>
#include <vector>

namespace bcc {

extern char const* const rc_name;

struct options
{
  static options from_argv(int argc, char* argv[]);

  /// Be verbose.
  bool verbose{ false };
  /// Include `command` string in the final `compile_commands.json`
  bool command{ false };
  /// Resolve symlinks of `file` entries in the `compile_commands.json`
  bool resolve{ false };
  /// Bazel command.
  std::filesystem::path bazel_command{};
  /// Replace Bazel compiler with `cc`.
  std::optional<std::string> compiler{};
  /// Bazel startup options.
  std::vector<std::string> bazel_startup_options;
  /// Output path of the `compile_commands.json` file.
  std::string output_path{ "%workspace%/compile_commands.json" };
  /// Bazel build configs to apply.
  std::vector<std::string> configs{};
  /// Any replacements to apply.
  std::vector<std::pair<std::string, std::string>> replace{};
  /// Targets to consider for the generation of the `compile_commands.json`
  /// file.
  std::vector<std::string> targets{ "//..." };
  /// Flags to be forwarded to the `bazel query` call.
  std::vector<std::string> bazel_flags{};
  /// Write current config to file.
  bool write_rc_file{ false };
  /// Path of config file if one is found.
  std::optional<std::filesystem::path> rcpath;

  std::ostream& write(std::ostream& os) const;
};
} // namespace bcc
