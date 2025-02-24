
// variant 3

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <type_traits>

#define _nn [[gnu::nonnull]]
#define _nl _Nullable
#define _nd [[nodiscard]]

#define _r(_x) { return _x; }

#define _cs(y, _x) \
    case y:        \
        _x;        \
        break;

typedef int* inp;
typedef char* ss;
typedef const char* cs;
typedef const int ci;
typedef const char cc;

/////////////////////////////

template<typename t>
class st {
public:
    t*        _nl ts = 0;
    int           sz = 0;
    const int     is = sizeof(int);

    void dd(_nn t* a) {
        ts = realloc(ts, 
            (sz + 1) * is);

        ts[sz] = a;
        sz++;
    }

    _nd bool mp() _r(!sz)

    _nd t* _nl pl() {
        if (mp()) return 0;
        t* a = ts[sz];
        
        ts = realloc(ts, 
            (sz - 1) * is);
        
        sz--;
        return a;
    }

    _nd t* _nl ls() {
        if (mp()) return 0;
        return ts[sz-1];
    }

    void fr(void (*_nl a)(t a) = 0) {
        if (mp()) return;

        for (; sz >= 0; sz--) {
            if (a) a(ts[sz]);
            delete ts[sz];
        }
        
        ts = realloc(ts, 0);
    }
};

/////////////////////////////

ci sgn = 4;
cc sg[sgn+1] = "+-/*";

ci nmn = 10;
cc nm[nmn+1] = "0123456789";

_nd cs _nl mt(char a, ci b, cs c) {
    for (int i = 0; i < b; i++) {
        if (a == c[i])
            return &c[i];
    }
    return 0;
}

ci bf = 16;

#define mts(x) mt(x, sgn, sg)
#define mtn(x) mt(s, nmn, nm)

/////////////////////////////

class cl {
public:
    ss  _nl gs = 0;
    inp _nl ns = 0;
    int     gi = 0;
    int     ni = 0;

    cl(_nn ss s)
    { ps(s); }

    void ps(_nn ss a) {
        int l = strlen(a);
        ss ns = new char[bf];

        for (int i = 0, j = 0; i < l; i++) {
            cs b = mts(a[i]);

            if (b) {
                ddg(*b);
                ddg(atoi(ns));

                j = 0;
                ns = new char[bf];
                continue;
            }

            ns[j] = a[i];
            j++;
        }
    }

    template<typename t>
    void ddg(t a) {
        if (std::is_same<t, char>::value) {
            gs = (ss) realloc(gs, 
                (gi + 1) * sizeof(char));

            gs[gi] = a;
            gi++;
        } else {
            ns = (inp) realloc(ns, 
                (ni + 1) * sizeof(int));

            ns[ni] = a;
            ni++;
        }
    }

    _nd _nn ss mkp() {
        ss s = new char[gi + ni*bf];
        
    }
};

/////////////////////////////

int main() {

    return 0;
}
