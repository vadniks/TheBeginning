#ifndef __cl
#define __cl

/* base class */

// just not to mess with the realloc
#include <vector>

#include "dcls.hpp"
#include "pr.hpp"

#define psc pr<cs, cl*>

// contains tree interaction methods
class cl {
protected:
    vector<psc*> bss; // subscribers (observers)
    ci& xy; // reference to matriz size
    int** mx; // matrix pointer
    int& x;
    int& y;
    cs& w;
    int& fg;

public:

    // parameters: the head object and the name which is zero (null) by default
    cl(ci& xy, int** mx, int& x, int& y, cs& w, int& fg);
    ~cl();
	
    void sbs(cs a, cl* b); // subscribe
    void brc(cs a, cs b); // broadcast a message
	
    __attribute__((deprecated, unused))
    void usb(int a); // unsubscribe

    // handler
    virtual void hnd(cs a) {}
};

#endif
