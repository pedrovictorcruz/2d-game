#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <memory>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <string>

class Logger
{
public:
  template <typename T> static void info(const T &message)
  {
    return Logger::instance().getConsoleLogger()->info(message);
  }

  template <typename T> static void warn(const T &message)
  {
    return Logger::instance().getConsoleLogger()->warn(message);
  }

  template <typename T> static void error(const T &message)
  {
    return Logger::instance().getConsoleLogger()->error(message);
  }

private:
  Logger()
  {
    // Inicializa os loggers
    consoleLogger = spdlog::stdout_color_mt("console");

    // Configura o nível de log
    spdlog::set_level(spdlog::level::debug);
    spdlog::flush_on(
        spdlog::level::err); // Garante que erros são escritos imediatamente
  }

  static Logger &instance()
  {
    static Logger loggerInstance;
    return loggerInstance;
  }

  // Obtém a instância do logger de console
  static std::shared_ptr<spdlog::logger> getConsoleLogger()
  {
    return instance().consoleLogger;
  }

private:
  std::shared_ptr<spdlog::logger> consoleLogger;
  std::shared_ptr<spdlog::logger> fileLogger;
};

#endif // LOGGER_HPP
