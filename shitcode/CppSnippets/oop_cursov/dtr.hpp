#ifndef __dtr
#define __dtr

#include "cl.hpp"

// class finds the unit (digit one) on the right (determine right)
class dtr final : public cl {
public:
    _cn(dtr)
    void hnd(cs a) override; // handler searches unit on the right
};

#endif
