#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace forge {

class Log {
public:
  static void Init();

  static inline std::shared_ptr<spdlog::logger> &GetCoreLogger() {
    return s_CoreLogger;
  }

  static inline std::shared_ptr<spdlog::logger> &GetClientLogger() {
    return s_ClientLogger;
  }

private:
  static std::shared_ptr<spdlog::logger> s_CoreLogger;
  static std::shared_ptr<spdlog::logger> s_ClientLogger;
};
} // namespace forge

// Core log macros
#define FRG_CORE_TRACE(...) ::forge::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FRG_CORE_INFO(...) ::forge::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FRG_CORE_WARN(...) ::forge::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FRG_CORE_ERROR(...) ::forge::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FRG_CORE_FATAL(...) ::forge::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define FRG_TRACE(...) ::forge::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FRG_INFO(...) ::forge::Log::GetClientLogger()->info(__VA_ARGS__)
#define FRG_WARN(...) ::forge::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FRG_ERROR(...) ::forge::Log::GetClientLogger()->error(__VA_ARGS__)
#define FRG_FATAL(...) ::forge::Log::GetClientLogger()->fatal(__VA_ARGS__)