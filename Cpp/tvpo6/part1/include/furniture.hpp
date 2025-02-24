
#pragma once

#include "decls.hpp"

class Furniture {
public:
    virtual ~Furniture() = default;
    virtual FurnitureType gtype() CONST_PURE_VIRTUAL
    virtual unsigned gcost() CONST_PURE_VIRTUAL
    virtual FurnitureColor gcolor() CONST_PURE_VIRTUAL
    virtual FurnitureMaterial gmaterial() CONST_PURE_VIRTUAL
    virtual c_str gname() CONST_PURE_VIRTUAL
    virtual c_str stringify() CONST_PURE_VIRTUAL
};
