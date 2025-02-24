
#include <cstdio>
#include <cstdlib>
#include "../include/factory.hpp"

int main(
    __attribute__((unused)) const int argc,
    __attribute__((unused)) c_str* const argv
) {
    Factory factory;
    auto furniture = factory.produceRandom();
    printf("%s\n", furniture->stringify());
    delete furniture;
    return EXIT_SUCCESS;
}
