
#include <cstdio>
#include <cstring>
#include <contract/contract.hpp>
#include "../include/baseFurniture.hpp"

c_str BaseFurniture::stringifyType() const { switch (type) {
    CASE(FurnitureType::CHAIR, return "chair")
    CASE(FurnitureType::TABLE, return "table")
    CASE(FurnitureType::SHELF, return "shelf")
    CASE_DEFAULT
} }

c_str BaseFurniture::stringifyColor() const { switch (color) {
    CASE(FurnitureColor::RED, return "red")
    CASE(FurnitureColor::GREEN, return "green")
    CASE(FurnitureColor::BLUE, return "blue")
    CASE(FurnitureColor::WHITE, return "white")
    CASE(FurnitureColor::BLACK, return "black")
    CASE_DEFAULT
} }

c_str BaseFurniture::stringifyMaterial() const { switch (material) {
    CASE(FurnitureMaterial::WOOD, return "wood")
    CASE(FurnitureMaterial::PLASTIC, return "plastic")
    CASE(FurnitureMaterial::METAL, return "metal")
    CASE_DEFAULT
} }

c_str BaseFurniture::stringify() const {
    unsigned dgts = digits(cost);
    char* string = new char[FURNITURE_STRING_LENGTH + 4];
    unsigned nmlen = strlen(name);

    contract(this) {
        precondition(name and cost > 0);
        invariant(dgts <= MAX_COST_LENGTH and dgts > 0
                  and string
                  and nmlen <= MAX_NAME_LENGTH and nmlen > 0);
        postcondition(string and strlen(string) > 0);
    };

    sprintf(string, "%s %u %s %s %s",
        stringifyType(), cost, stringifyColor(), stringifyMaterial(), name);

    return string;
}

BaseFurniture::BaseFurniture(FurnitureType ntype, FURNITURE_PARAMS) {
    contract(ctor) { precondition(ncost > 0 and nname and strlen(nname) <= MAX_NAME_LENGTH); };
    type = ntype; cost = ncost; color = ncolor; material = nmaterial; name = nname;
}
