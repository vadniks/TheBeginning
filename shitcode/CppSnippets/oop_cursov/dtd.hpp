#ifndef __dtd
#define __dtd

#include "cl.hpp"

// class finds the unit (digit one) below (determine down)
class dtd final : public cl {
public:
    _cn(dtd)
    void hnd(cs a) override; // handler searches unit below
};

#endif
