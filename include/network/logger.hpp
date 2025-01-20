#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <sys/stat.h>
#include <sys/types.h>
#include <map>
#include <string>

// Log levels enumeration
enum LogLevel { DEBUG_LEVEL, INFO_LEVEL, WARNING_LEVEL, ERROR_LEVEL, CRITICAL_LEVEL };

class Logger {
private:
    std::map<LogLevel, std::ofstream> logFiles;
    std::string logDir;

    void ensure_directory_exists(const std::string& path);
    std::string levelToString(LogLevel level);
    void initLogFiles();

public:
    Logger(const std::string& directory);
    ~Logger();
    void log(LogLevel level, const std::string& message);
};

#endif  // LOGGER_HPP
