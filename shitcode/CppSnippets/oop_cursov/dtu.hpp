#ifndef __dtu
#define __dtu

#include "cl.hpp"

// class finds the unit (digit one) above (determine up)
class dtu final : public cl {
public:
    _cn(dtu)
    void hnd(cs a) override; // handler searches unit above
};

#endif
