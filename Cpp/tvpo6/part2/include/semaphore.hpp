
#pragma once

#include <mutex>
#include <condition_variable>

class Semaphore final {
private:
    std::mutex mutex;
    std::condition_variable condition;
    unsigned long count = 0;

public:
    void release();
    void acquire();
    bool tryAcquire();
};
