#include "rateLimiter.h"

bool RateLimiter::isAllowed() {
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<int> durationSinceStart = std::chrono::duration_cast<std::chrono::seconds>(now - windowStartTime);

    if (durationSinceStart.count() > timeWindow) {
        windowStartTime = now;
        requestCount = 0;
    }

    if (requestCount < maxRequests) {
        requestCount++;
        return true;
    } else {
        return false;
    }
}
