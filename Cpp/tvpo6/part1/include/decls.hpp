
#pragma once

#define OVERRIDE_PURE_CONST(x) const override { return x; }
#define CASE(x, y) case x: y; break;
#define CASE_DEFAULT default: throw 1;
#define FURNITURE_PARAMS unsigned ncost, FurnitureColor ncolor, FurnitureMaterial nmaterial, c_str nname
#define DIVISIBLE(x, y) (x % y == 0)
#define ABS(x) (x >= 0 ? x : -x)
#define CONST_PURE_VIRTUAL const = 0;

#define SPECIFIC_FURNITURE(x, y) \
    class x final: public BaseFurniture { \
    public: \
        x(FURNITURE_PARAMS) \
        : BaseFurniture(FurnitureType::y, ncost, ncolor, nmaterial, nname) {} \
    };

typedef unsigned char byte;
typedef char const* c_str;
typedef const unsigned c_uint;

enum FurnitureType { CHAIR = 0, TABLE = 1, SHELF = 2 };
enum FurnitureColor { RED = 0, GREEN = 1, BLUE = 2, WHITE = 3, BLACK = 4 };
enum FurnitureMaterial { WOOD = 0, PLASTIC = 1, METAL = 2 };

extern c_uint MAX_TYPE_LENGTH;
extern c_uint MAX_COST_LENGTH;
extern c_uint MAX_COLOR_LENGTH;
extern c_uint MAX_MATERIAL_LENGTH;
extern c_uint MAX_NAME_LENGTH;
extern c_uint FURNITURE_STRING_LENGTH;

unsigned digits(unsigned $int);
