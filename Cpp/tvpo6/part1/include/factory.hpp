
#pragma once

#include "decls.hpp"
#include "furniture.hpp"
#include "baseFurniture.hpp"

SPECIFIC_FURNITURE(Chair, CHAIR)
SPECIFIC_FURNITURE(Table, TABLE)
SPECIFIC_FURNITURE(Shelf, SHELF)

class Factory final { public: Furniture* produceRandom() const; };
