
#include <cstdlib>
#include <thread>
#include <vector>
#include "../include/barbershop.hpp"

int main(
    __attribute__((unused)) const int argc,
    __attribute__((unused)) const char** const argv
) {
    Barbershop barbershop;
    std::vector<std::thread*> barberTaskThreads, customerTaskThreads;

    for (unsigned i = 0, j = 0; i < 8; i++) {
        barberTaskThreads.push_back(new std::thread([&]{ barbershop.startService(j++); }));
        customerTaskThreads.push_back(new std::thread([&]{ barbershop.receiveNewCustomer(j++); }));
    }
    for (auto i : barberTaskThreads) {
        i->join();
        delete i;
    }
    for (auto i : customerTaskThreads) {
        i->join();
        delete i;
    }
    return EXIT_SUCCESS;
}
