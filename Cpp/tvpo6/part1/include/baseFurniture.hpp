
#pragma once

#include "furniture.hpp"
#include "decls.hpp"

class BaseFurniture : public Furniture {
private:
    c_str stringifyType() const;
    c_str stringifyColor() const;
    c_str stringifyMaterial() const;
protected:
    FurnitureType type;
    unsigned cost;
    FurnitureColor color;
    FurnitureMaterial material;
    c_str name;

public:
    FurnitureType gtype() OVERRIDE_PURE_CONST(type)
    unsigned gcost() OVERRIDE_PURE_CONST(cost)
    FurnitureColor gcolor() OVERRIDE_PURE_CONST(color)
    FurnitureMaterial gmaterial() OVERRIDE_PURE_CONST(material)
    c_str gname() OVERRIDE_PURE_CONST(name)
    c_str stringify() const override;

    BaseFurniture(FurnitureType ntype, FURNITURE_PARAMS);
};
