#include "network/logger.hpp"

void Logger::ensure_directory_exists(const std::string& path) {
    struct stat info;
    if (stat(path.c_str(), &info) != 0) {
        if (mkdir(path.c_str(), 0777) != 0) {
            std::cerr << "Error: Could not create directory " << path << std::endl;
        } else {
            std::cout << "Directory created: " << path << std::endl;
        }
    } else {
        std::cout << "Directory already exists: " << path << std::endl;
    }
}

std::string Logger::levelToString(LogLevel level) {
    switch (level) {
        case DEBUG_LEVEL: return "DEBUG";
        case INFO_LEVEL: return "INFO";
        case WARNING_LEVEL: return "WARNING";
        case ERROR_LEVEL: return "ERROR";
        case CRITICAL_LEVEL: return "CRITICAL";
        default: return "UNKNOWN";
    }
}

void Logger::initLogFiles() {
    for (int level = DEBUG_LEVEL; level <= CRITICAL_LEVEL; ++level) {
        std::string filename = logDir + "/" + levelToString(static_cast<LogLevel>(level)) + ".log";
        logFiles[static_cast<LogLevel>(level)].open(filename, std::ios::app);

        if (!logFiles[static_cast<LogLevel>(level)].is_open()) {
            std::cerr << "Error opening log file: " << filename << std::endl;
        }
    }
}

Logger::Logger(const std::string& directory) : logDir(directory) {
    ensure_directory_exists(logDir);
    initLogFiles();
}

Logger::~Logger() {
    for (auto& file : logFiles) {
        if (file.second.is_open()) {
            file.second.close();
        }
    }
}

void Logger::log(LogLevel level, const std::string& message) {
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

    std::ostringstream logEntry;
    logEntry << "[" << timestamp << "] "
             << levelToString(level) << ": " << message
             << std::endl;

    std::cout << logEntry.str();

    if (logFiles[level].is_open()) {
        logFiles[level] << logEntry.str();
        logFiles[level].flush();
    }
}
