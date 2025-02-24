
#pragma once

#include <mutex>
#include "semaphore.hpp"
#include "barber.hpp"

class Barbershop {
private:
    const unsigned limit = 4;
    Barber barber;
    Semaphore customerReady;
    Semaphore barberReady;
    Semaphore customerDone;
    Semaphore barberDone;
    std::mutex mutex;

public:
    unsigned customers;

    Barbershop() = default;
    ~Barbershop() = default;
    void startService(unsigned id);
    void receiveNewCustomer(unsigned id);
};
