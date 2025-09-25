#pragma once

#include <vector>
#include <string>


class Logger
{
    enum LogType 
    {
        LOG_INFO,
        LOG_WARNING,
        LOG_ERROR
    };

    struct LogEntry {
        LogType type;
        std::string message;
    };
public:
    static void INFO(const std::string& message);
    static void ERR(const std::string& message);
    static void WARNING(const std::string& message);

private:
    inline static std::vector<LogEntry> logMessages;
};