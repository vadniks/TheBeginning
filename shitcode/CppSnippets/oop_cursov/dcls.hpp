#ifndef __dcls
#define __dcls

// helper declarations

#define ths    (*this)
#define _r(_x) { return _x; } // aka one-line method

// constructor
#define _cn(x)                                            \
    x(ci& xy, int** mx, int& x, int& y, cs& w, int& fg) : \
        cl(xy, mx, x, y, w, fg) {}

// bounds checking
#define chk(x) x >= 0 and x < xy ? x : throw 1

// compact case for the switch
#	define _cs(y, _x) \
        case y:	      \
            _x;	      \
            break;

///////////////////////////////

// string
typedef char* ss;

typedef const char* cs;
typedef const int ci;

using namespace std;

// string buffer length
ci bf = 64;

#endif
