// 02_Logger.cpp

#include <iostream>
#include <string>
#include "02_Logger.h"

Logger::Logger() : logCount(0) {

}

Logger::~Logger() {
    std::cout << "Logger instance destroyed." << std::endl;
}

void Logger::logInfo(const std::string& message) {
    ++logCount;
    std::cout << "[Info]" << message << std::endl;
}
void Logger::logWarning(const std::string& message) {
    ++logCount;
    std::cout << "[Warning]" << message << std::endl;
}
void Logger::logError(const std::string& message) {
    ++logCount;
    std::cout << "[Error]" << message << std::endl;
}
void Logger::showTotalLogs() const {
    std::cout << "Total logs recorded: " << logCount << std::endl;
}