
///////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

///////////////////////////////////

#define interface class

#define _stb {}
#define _r(_x) { return _x; }

#define _clc int clt(int x) override

#define _cs(y, _x) \
    case y:        \
        _x;        \
        break;

#define ct(_x, y) [[unused]] cout << _x; if (y) cout << endl;

#define _dst(cls) ~cls() = default;
#define _xpw (int) pow(x, e)
#define _exp(x) { this->e = x; }

using namespace std;

typedef const int ci;

///////////////////////////////////

interface I {

public:
    int e;
    virtual int clt(int x) = 0;
    I() = default;
    virtual _dst(I)
};

///////////////////////////////////

ci aa = 1;
ci bb = 2;
ci cc = 3;
ci dd = 4;

///////////////////////////////////

class A : public I {
private:
    int e = aa;

public:
    int a;

    A(int a) : a(a) _stb

    _dst(A)

    _clc _r(a * _xpw)
};

class B : public A {
private:
    int e = bb;

public:
    int b;

    B(int a, int b) : 
        b(b), A(a) 
    _stb

    _dst(B)

    _clc _r(b * _xpw)
};

class C : public B {
private:
    int e = cc;

public:
    int c;

    C(int a, int b, int c) :
        c(c), B(a, b) 
    _stb

    _dst(C)

    _clc _r(c * _xpw)
};

class D : public C {
private:
    int e = dd;

public:
    int d;

    D(int a, int b, int c, int d) : 
        d(d), C(a, b, c) 
    _stb

    _dst(D)

    _clc _r(d * _xpw)
};

///////////////////////////////////

int main() {
    int
        a = 0,
        b = 0,
        c = 0,
        d = 0,
        
        x = 0,
        e = 0,
        
        rs = 0;

    cin >> a >> b >> c >> d;
    printf(
        "a1 = %d    a2 = %d    a3 = %d    a4 = %d", 
        a, b, c, d);
    D dp(a, b, c, d);

    while (1) {
        cin >> x >> e;
        if (!x) break;

        printf("\n");

        switch (e) {
            _cs(aa, rs = ((A) dp).clt(x))
            _cs(bb, rs = ((B) dp).clt(x))
            _cs(cc, rs = ((C) dp).clt(x))
            _cs(dd, rs = ((D) dp).clt(x))
        }

        printf("Class %d    F( %d ) = %d", e, x, rs);
    }

    return 0;
}

///////////////////////////////////
