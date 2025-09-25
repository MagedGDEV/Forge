#include "logger.h"

#include <chrono>
#include <ctime>

std::string getCurrentTime()
{
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string out(30, '\0');
    std::size_t outLen = std::strftime(&out[0], out.size(),"%d-%b-%Y %H:%M:%S", std::localtime(&now));
    out.resize(outLen);
    return out;
}

void Logger::INFO(const std::string& message)
{
    
    LogEntry logEntry;
    logEntry.type = LOG_INFO;
    logEntry.message = "\x1B[32m[INFO][" + getCurrentTime() + "]: \033[0m" + message + '\n';
    
    printf("%s", logEntry.message.c_str());

    logMessages.push_back(logEntry);    
}

void Logger::ERR(const std::string& message)
{
    LogEntry logEntry;
    logEntry.type = LOG_ERROR;
    logEntry.message = "\x1B[91m[ERROR][" + getCurrentTime() + "]: \033[0m" + message + '\n';
    
    printf("%s", logEntry.message.c_str());
    
    logMessages.push_back(logEntry);     
}

void Logger::WARNING(const std::string& message)
{
    LogEntry logEntry;
    logEntry.type = LOG_ERROR;
    logEntry.message = "\x1B[33m[WARNING][" + getCurrentTime() + "]: \033[0m" + message + '\n';
    
    printf("%s", logEntry.message.c_str());
    
    logMessages.push_back(logEntry);     
}