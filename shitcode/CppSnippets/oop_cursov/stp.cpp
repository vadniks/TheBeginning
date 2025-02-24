
// step class implementation

#include "stp.hpp"
#include <cstring>

// each step processing
void stp::hnd(cs a) {
    if (!strcmp(a, "abv")) {
        x--;
        w = "fblw";
    } else if (!strcmp(a, "rgh")) {
        y++;
        w = "flft";
    } else if (!strcmp(a, "blw")) {
        x++;
        w = "fabv";
    } else if (!strcmp(a, "stp"))
        fg++;
	
    mx[x][y] = 2;
}
