/*_   __         _           __    ___ 
 | | / /__ _____(_)__ ____  / /_  |_  |
 | |/ / _ `/ __/ / _ `/ _ \/ __/ / __/ 
 |___/\_,_/_/ /_/\_,_/_//_/\__/ /____/ 
*/

/*
/~_/~`/~` //~`| _  _  _  / __|_ _|--/~`_|__|_'| ~/
\_/\_,\_,/ \_,|(_|| |(_|/ _\ | (_|--\_, !  ! .|./ 
                      _|                          
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <chrono>

#define _cs(y, _x) \
    case y:        \
        _x;        \
        break;

#define _nn [[gnu::nonnull]]
#define _nl _Nullable
#define _nd [[nodiscard]]

#define foo(x, y) fopen(x, !y ? "r" : "w")
#define fo(x, y) foo(x, y);
#define fc(x) fclose(x);

#pragma GCC diagnostic ignored "-Wpointer-bool-conversion"

typedef const char* cs;
typedef char* ss;
typedef FILE* fpt;

cs fa = "a.bin";
cs fb = "b.bin";
cs fc = "c.bin";

cs st = "%s";

const int xn = 64;

/////////////////////////////////////

[[gnu::unused]]
long long cm = 0;
long long mv = 0;

#define _C_(_x, y...) ([y]() { cm++; return _x; })()
#define _M_ mv++;

/////////////////////////////////////

const int rwn = 6;
struct row {
    ss ln;
    ss nn;
    ss db;
    int w;
    int h;
    bool sx;

    row() {}

#   define tg h

};
typedef row* rwp;

/////////////////////////////////////

_nd _nn
ss sbs(_nn ss a, int i, int& k) {
    int l = strlen(a);
    ss b = new char[l];
    
    for (int j = 0; j < l; j++) {
        if (j == i) {
            b[j] = '\0';
            break;
        }
        b[j] = a[j];
    }
    return b;
}

ss sbs(ss a, int i) {
    [[gnu::unused]] int j = 0;
    return sbs(a, i, j);
}

/////////////////////////////////////

_nd _nl
rwp r(_nn fpt f) {
    if (!f) return 0;

    ss a = new char[xn];
    int j = 0;
    bool k = 0;
    rwp r = new row();

    while (fscanf(f, st, a) != EOF) {
        a = (j < rwn-1) ? sbs(a, strlen(a)-1) : a;

        switch (j) {
            _cs(0, r->ln = a)
            _cs(1, r->nn = a)
            _cs(2, r->db = a)
            _cs(3, r->w  = atoi(a))
            _cs(4, r->h  = atoi(a))
            _cs(5, r->sx = a[0] == '0' ? 0 : 1)
        }
        a = new char[xn];

        if (j == rwn-1) {
            k = 1;
            break;
        } else j++;
    }

    return k ? r : 0;
}

/////////////////////////////////////

bool w(_nn fpt f, _nn rwp rr) {
    if (!f) return 0;

    if (!rr) return 0;
    row r = *rr;

    for (int j = 0;;) {
        void* t = 0;
        switch (j) {
            _cs(0, t = r.ln)
            _cs(1, t = r.nn)
            _cs(2, t = r.db)
            _cs(3, t = &r.w)
            _cs(4, t = &r.h)
            _cs(5, t = &r.sx)
        }
        
        j < 3 ? fprintf(f, "%s", t) : 
            j < rwn-1 ? 
                fprintf(f, "%d", *((int*) t)) : 
                    fprintf(f, "%d", *((bool*) t));

        if (j == rwn-1) {
            fprintf(f, "\n");
            break;
        } else {
            fprintf(f, ", ");
            j++;
        }
    }

    return 1;
}

/////////////////////////////////////

_nd
int fsz(_nn fpt f) {
    int sz = 0;

    if (!f)
        return -1;
    else {
        ss s = new char[xn];
    
        while (fgets(s, xn, f) != 0)
            sz++;
    
        fclose(f);
        return sz;
    }
}

/////////////////////////////////////

void srt() {
    rwp a1 = 0, a2 = 0;
    int i = 0, j = 0, t = 0;
    
#   define rn1 a1 != 0
#   define rn2 a2 != 0

    fpt f, f1, f2;
    int sz = fsz(foo(fa, 0));

    int k = 1;
    while (k < sz) {
        f = fo(fa, 0)
        f1 = fo(fb, 1)
        f2 = fo(fc, 1)
        
        int ia = 0;

        a1 = r(f);
        while (rn1) {
            for (i = 0; i < k and rn1; i++) {
                w(f1, a1);
                a1 = r(f);
            }
            for (j = 0; j < k and rn1; j++) {
                w(f2, a1);
                a1 = r(f);
            }
        }

        freopen(fa, "w", f);
        freopen(fb, "r", f1);
        freopen(fc, "r", f2);

        int bi = 0, ci = 0;

        a1 = r(f1);
        a2 = r(f2);

        while (rn1 and rn2) {
            i = 0, j = 0;
            while (i < k and j < k and rn1 and rn2) {
                if (a1->tg < a2->tg) {
                    w(f, a1);
                    a1 = r(f1);
                    i++;
                }
                else {
                    w(f, a2);
                    a2 = r(f2);
                    j++;
                }
            }
            while (i < k and rn1) {
                w(f, a1);
                a1 = r(f1);
                i++;
            }
            while (j < k and rn2) {
                w(f, a2);
                a2 = r(f2);
                j++;
            }
        }
        while (rn1) {
            w(f, a1); _M_
            a1 = r(f1);
            i++;
        }
        while (rn2) {
            w(f, a2); _M_
            a2 = r(f2);
            j++;
        }
        k *= 2;

        fc(f) fc(f1) fc(f2)
    }
}

/*
jj, kk, ll, 9, 10, 1
aa, bb, cc, 3, 4, 1
ln, nn, db, 1, 2, 0
gg, hh, ii, 7, 8, 0
dd, ee, ff, 5, 6, 1
*/

/////////////////////////////////////

_nd
bool rng(_nn fpt f) {
    int t;

    t = fgetc(f);
    t = fgetc(f);
    
    if (t != '\'') 
        fseek(f, -2, 1);
    else 
        fseek(f, 1, 1);
    
    return t == '\'';
}

// 5 1 7 3 9 0 8 7 4 6 2 8 

void srt2() {
    int s1, s2, m;
    rwp a1, a2;
    fpt f, f1, f2;
    s1 = s2 = 1;

#   define rn1 a1 != 0
#   define rn2 a2 != 0
    
    while (s1 > 0 and s2 > 0) {
        m = 1;
        s1 = 0;
        s2 = 0;

        f = fo(fa, 0)
        f1 = fo(fb, 1)
        f2 = fo(fc, 1)
        
        a1 = r(f);
        if (a1 != 0)
            w(f1, a1);
        
        if (a1 != 0)
            a2 = r(f);

        while (rn1 and rn2) {
            if (a2->tg < a1->tg) {
                switch (m) {
                    _cs(1,
                        fprintf(f1, "' "); 
                        m = 2; 
                        s1++)
                    _cs(2,
                        fprintf(f2, "' "); 
                        m = 1; 
                        s2++)
                }
            }

            if (m == 1) {
                w(f1, a2);
                s1++; 
            } else {
                w(f2, a2);
                s2++;
            }

            a1 = a2;
            a2 = r(f);
        }

        if (s2 > 0 and m == 2) 
            fprintf(f2, "'");

        if (s1 > 0 and m == 1) 
            fprintf(f1, "'");
        
        freopen(fa, "w", f);
        freopen(fb, "r", f1);
        freopen(fc, "r", f2);

        a1 = r(f1);
        a2 = r(f2);
        
        bool fl1, fl2;
        while (rn1 and rn2) {
            fl1 = fl2 = 0;
        
            while (!fl1 and !fl2) {
                if (a1->tg <= a2->tg) {
                    w(f, a1);
                    fl1 = rng(f1);
                    a1 = r(f1);
                } else {
                    w(f, a2);
                    fl2 = rng(f2);
                    a2 = r(f2);
                }
            } 
            while (!fl1) {
                w(f, a1);
                fl1 = rng(f1);
                a1 = r(f1);
            }
            while (!fl2) {
                w(f, a2);
                fl2 = rng(f2);
                a2 = r(f2);
            }
        }
        fl1 = fl2 = 0;
        while (!fl1 and rn1) {
            w(f, a1); _M_
            fl1 = rng(f1);
            a1 = r(f1);
        }
        while (!fl2 and rn2) {
            w(f, a2); _M_
            fl2 = rng(f2);
            a2 = r(f2);
        }
        fc(f) fc(f1) fc(f2)
    }
}

/////////////////////////////////////

/*
jj, kk, ll, 9, 10, 1
aa, bb, cc, 3, 4, 1
ln, nn, db, 1, 2, 0
gg, hh, ii, 7, 8, 0
dd, ee, ff, 5, 6, 1
*/

const int xxn = 100000;

void rnd(int n) {
    if (n > xxn || n < 1) throw -1;

    fpt f = fo(fa, 1);
    srand(time(0));
    char a[3] = { 'l', 'n', '\0' };

    for (int i = 0; i < n; i++) {
        int b = rand() % 100000 + 0;

        rwp r = new row();
        r->ln = a;
        r->nn = a;
        r->db = a;
        r->w = i;
        r->h = b;
        r->sx = 0;

#       if 0
        printf("%d %d %d\n", n, i, b);
#       endif

        w(f, r);
    }
    fc(f);
}

void drt(void (*a)(void)) {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;    
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    a();
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> b = t2 - t1;
    printf("\n%g\n\n",  b.count());
}

int main() {
    const int n = 10000;

#   if 0
    rnd(n);
#   endif

#   if 0
    return 0;
#   endif

    drt(&
#   if 0
        srt
#   else
        srt2
#   endif
    );

    printf("%d %lld\n", n, mv);

    return 0;
}
