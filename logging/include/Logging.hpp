#ifndef CARDGAMES_LOGGING_HPP
#define CARDGAMES_LOGGING_HPP

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_sinks.h>

#include <memory>
#include <string>

namespace cardgames::logging{

class Logger
{
public:
  template<typename T>
  static Logger createLogger(const T& name)
  {
    return Logger(name);
  }
  
  template<typename... Args>
  void warn(fmt::format_string<Args...> fmt, Args &&...args)
  {
    mLogger->warn(fmt, std::forward<Args>(args)...);
  }

  template<typename... Args>
  void error(fmt::format_string<Args...> fmt, Args &&...args)
  {
    mLogger->error(fmt, std::forward<Args>(args)...);
  }

  template<typename... Args>
  void critical(fmt::format_string<Args...> fmt, Args &&...args)
  {
    mLogger->critical(fmt, std::forward<Args>(args)...);
  }
  
  template<typename... Args>
  void trace(fmt::format_string<Args...> fmt, Args &&...args)
  {
    mLogger->trace(fmt, std::forward<Args>(args)...);
  }
  
  template<typename... Args>
  void debug(fmt::format_string<Args...> fmt, Args &&...args)
  {
    mLogger->debug(fmt, std::forward<Args>(args)...);
  }
  
  template<typename... Args>
  void info(fmt::format_string<Args...> fmt, Args &&...args)
  {
    mLogger->info(fmt, std::forward<Args>(args)...);
  }

private:
  template<typename T>
  Logger(const T& name)
    : mLogger(spdlog::stdout_logger_mt(name))
  {
    mLogger->set_level(spdlog::level::trace);
  }

  std::shared_ptr<spdlog::logger> mLogger;
};

}

#endif
