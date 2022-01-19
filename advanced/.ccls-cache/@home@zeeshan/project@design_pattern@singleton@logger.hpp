
#pragma once

#include <fstream>
#include <string>
#include <mutex>

//TODO: Use this mechanism
enum class Severity{INFO, WARN, ERROR};
#define STINGIFY(sev) std::string{#sev}.substr(std::string{#sev}.find("::")+1)
std::ostream& operator<<(std::ostream& os, Severity const & sev)
{
        return os << STINGIFY(sev);
}

class Logger
{
    public:

        static Logger& instance(std::string const & file);
        void info(std::string const & message);
        void error(std::string const & message);
        void warn(std::string const & message);
        Logger(Logger const &)=delete;
        Logger& operator=(Logger const &)=delete;

    private:

        void write(std::string const & message, std::string const & severity); 
        Logger(std::string const & file) : _log_file{file}{}

        std::ofstream  _log_file;
        static Logger* _instance;
        static std::mutex _mutex;
};

Logger* Logger::_instance = nullptr;
std::mutex Logger::_mutex;

Logger& Logger::instance(std::string const & file)
{
    std::lock_guard<std::mutex> lock(_mutex);
    if(!_instance)
        _instance = new Logger{file};
    return *_instance;
}

void Logger::write(std::string const & message, std::string const & severity)
{
    _log_file << "[" << severity <<"] => " << message << std::endl;
}

void Logger::info(std::string const & message)
{
    write(message, "INFO");
}

void Logger::warn(std::string const & message)
{
    write(message, "WARN");
}

void Logger::error(std::string const & message)
{
    write(message, "ERROR");
}
