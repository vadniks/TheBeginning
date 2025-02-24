
#include <contract/contract.hpp>
#include "../include/decls.hpp"

c_uint MAX_TYPE_LENGTH = 5;
c_uint MAX_COST_LENGTH = 5;
c_uint MAX_COLOR_LENGTH = 5;
c_uint MAX_MATERIAL_LENGTH = 7;
c_uint MAX_NAME_LENGTH = 10;
c_uint FURNITURE_STRING_LENGTH =
    MAX_TYPE_LENGTH +
    MAX_COST_LENGTH +
    MAX_COLOR_LENGTH +
    MAX_MATERIAL_LENGTH +
    MAX_NAME_LENGTH;

unsigned digits(unsigned $int) {
    unsigned count = 0;
    contract(fun) { postcondition(count > 0); };

    do { count++; $int /= 10; } while ($int);
    return count;
}
