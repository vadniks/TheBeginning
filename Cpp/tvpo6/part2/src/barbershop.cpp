
#include <cstdio>
#include "../include/barbershop.hpp"
#include "../include/customer.hpp"

void Barbershop::startService(unsigned id) {
    customerReady.acquire();
    barberReady.release();
    barber.cutHair(id);
    customerDone.acquire();
    barberDone.release();
    printf("Haircut is done for %u\n", id);
}

void Barbershop::receiveNewCustomer(unsigned id) {
    Customer customer(id);
    customer.enter();

    mutex.lock();
    if (customers == limit) {
        mutex.unlock();
        customer.leave();
        return;
    }
    customers++;
    mutex.unlock();

    customerReady.release();
    barberReady.acquire();
    customer.getHairCut();
    customerDone.release();

    barberDone.acquire();
    mutex.lock();
    customers--;
    mutex.unlock();
}
