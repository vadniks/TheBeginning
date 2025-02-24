#ifndef __pr
#define __pr

// pair of two values with generic types
template<
    typename l, 
    typename r>
struct pr {
    l a = 0; // left
    r b = 0; // right

    pr(l a, r b) : a(a), b(b) {}
    ~pr() = default;
};

#endif
