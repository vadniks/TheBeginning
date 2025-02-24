
#pragma once

#include <cstdio>

class Customer {
private:
    unsigned id;
public:
    explicit Customer(unsigned _id) { id = _id; }
    void enter() { printf("Customer %u: Enters the shop\n", id); }
    void getHairCut() { printf("Customer %u: Getting Haircut\n", id); }
    void leave() { printf("Customer %u: Leaves the shop\n", id); }
};
