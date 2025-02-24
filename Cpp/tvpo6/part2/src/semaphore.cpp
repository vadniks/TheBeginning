
#include "../include/semaphore.hpp"

#define MTX decltype(mutex)

void Semaphore::release() {
    std::lock_guard<MTX> lock(mutex);
    count++;
    condition.notify_one();
}

void Semaphore::acquire() {
    std::unique_lock<MTX> lock(mutex);
    while (!count) condition.wait(lock);
    count--;
}

bool Semaphore::tryAcquire() {
    std::lock_guard<MTX> lock(mutex);
    if (count) { count--; return true; }
    return false;
}
