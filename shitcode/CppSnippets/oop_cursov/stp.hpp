#ifndef __stp
#define __stp

#include "cl.hpp"
#include "dcls.hpp"

// class for processing each step
class stp final : public cl {
public:
    _cn(stp)
    void hnd(cs a) override; // steps prosessing (handler)
};

#endif
