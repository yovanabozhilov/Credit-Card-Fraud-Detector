#ifndef RATE_LIMITER_H
#define RATE_LIMITER_H

#include <chrono>

class RateLimiter {
private:
    int maxRequests;
    int timeWindow; 
    int requestCount;
    std::chrono::steady_clock::time_point windowStartTime;

public:
    RateLimiter(int maxRequests, int timeWindow)
        : maxRequests(maxRequests), timeWindow(timeWindow), requestCount(0) {
        windowStartTime = std::chrono::steady_clock::now();
    }

    bool isAllowed();
};

#endif 
