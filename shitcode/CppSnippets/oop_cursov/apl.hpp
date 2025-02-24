#ifndef __apl
#define __apl

/* application */

#include "dcls.hpp"
#include "cl.hpp"

#define inst inline static

class apl final : cl {
private:
    // matrix initialization
    static int** nt();

    inst ci xyn = 3; // size of row/column
    inst int** mmx = nt();
    inst int xx = 0;
    inst int yy = 0;
    inst cs ww = "";
    inst int fgg = 0;

public:

    apl();

    // finds the source unit (digit '1') and returns 1
    // returns 0 otherwise
    void fdu();
};

#endif
