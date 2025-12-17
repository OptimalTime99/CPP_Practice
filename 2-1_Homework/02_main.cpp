// 스마트 포인터를 활용한 로그분석기 구현
// 02_main.cpp

#include <memory>
#include "02_Logger.h"


int main() {
    std::unique_ptr<Logger> logger = std::make_unique<Logger>();

    logger->logInfo("System is starting.");
    logger->logWarning("Low disk space.");
    logger->logError("Unable to connect to the server.");

    logger->showTotalLogs();

    return 0;
}