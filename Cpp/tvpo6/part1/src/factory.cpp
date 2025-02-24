
#include <contract/contract.hpp>
#include <type_traits>
#include <ctime>
#include <cstdlib>
#include "../include/factory.hpp"

template<typename T, typename = typename std::enable_if<std::is_base_of<BaseFurniture, T>::value>::type>
T* produceSpecific(FURNITURE_PARAMS) {
    T* result = 0;
    unsigned dgts = digits(ncost);

    contract(fun) {
        precondition(ncost > 0 and nname);
        invariant(dgts < MAX_COST_LENGTH);
        postcondition(result);
    };

    result = new T(ncost, ncolor, nmaterial, nname);
    return result;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
Furniture* Factory::produceRandom() const {
    srand(time(0)); // NOLINT(cert-msc51-cpp,modernize-use-nullptr)

    unsigned rnd = 0 + ABS(rand()) % (3 - 0 + 1);
    unsigned cost = rnd * 100 + 1;
    Furniture* result = 0;

    char* name = new char[MAX_NAME_LENGTH];
    unsigned i = 0;
    for (; i < MAX_NAME_LENGTH; name[i++] = static_cast<char>(97 + ABS(rand()) % (122 - 97 + 1)));
    name[i] = '\0';

    contract(this) {
        invariant(cost > 0 and name);
        postcondition(result);
    };

    if (DIVISIBLE(rnd, 3))
        result = produceSpecific<Chair>(cost, FurnitureColor::RED, FurnitureMaterial::WOOD, name);
    else if (DIVISIBLE(rnd, 2))
        result = produceSpecific<Table>(cost, FurnitureColor::GREEN, FurnitureMaterial::PLASTIC, name);
    else
        result = produceSpecific<Shelf>(cost, FurnitureColor::BLUE, FurnitureMaterial::METAL, name);

    return result;
}
#pragma clang diagnostic pop
