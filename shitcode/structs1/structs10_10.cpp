/*
                      .--,-``-.     
                     /   /     '.   
       ,---.        / ../        ;  
      /__./|        \ ``\  .`-    ' 
 ,---.;  ; |         \___\/   \   : 
/___/ \  | |              \   :   | 
\   ;  \ ' |              /  /   /  
 \   \  \: |              \  \   \  
  ;   \  ' .          ___ /   :   | 
   \   \   '         /   /\   /   : 
    \   `  ;        / ,,/  ',-    . 
     :   \ |        \ ''\        ;  
      '---"          \   \     .'   
                      `--`-,,-'     
_____/\\\\\\\\\\\\_________/\\\\\\\\\_________/\\\\\\\\\_        
 ___/\\\//////////_______/\\\////////_______/\\\////////__       
  __/\\\________________/\\\/______________/\\\/___________      
   _\/\\\____/\\\\\\\___/\\\_______________/\\\_____________     
    _\/\\\___\/////\\\__\/\\\______________\/\\\_____________    
     _\/\\\_______\/\\\__\//\\\_____________\//\\\____________   
      _\/\\\_______\/\\\___\///\\\____________\///\\\__________  
       _\//\\\\\\\\\\\\/______\////\\\\\\\\\_____\////\\\\\\\\\_ 
        __\////////////___________\/////////_________\/////////__
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <chrono>

#define _nn [[gnu::nonnull]]
#define _nl _Nullable
#define _nd [[nodiscard]]

#define _sch(x)     \
    class x final { \
    private:        \
        x() {}      \
        ~x() {}     \
    public:

typedef char* ss;
typedef FILE* fl;

///////////////////////////////

const int 
    tln = 7,
    rsn = 8,
    ndn = 2,
    bf  = tln + rsn,
    soc = sizeof(char);

struct nd final {
    /*_nn*/ ss tl;
    /*_nn*/ ss rs;

#   define tg tl

    nd(_nn ss tl, _nn ss rs) :
        tl(tl), rs(rs)
    {}

    [[deprecated, gnu::unused]]
    _nd bool operator>(nd const& d) 
    { return atoi(this->tg) > atoi(d.tl); }

    _nd static 
    bool cmt(_nn ss a, _nn ss b, bool c = 0)
    { return atoi(a) 
#       if c
            <
#       else
            >
#       endif
    atoi(b); }

};
typedef nd* ndp;

///////////////////////////////

char const* fn = "a.bin";

_sch(fio)

    _nd static ndp _nl rd(_nn fl f) {
        ss s = new char[bf];

        if (fread(s, soc, bf, f) != bf)
            return 0;

        ndp dd = new nd(
            new char[tln], 
            new char[rsn]
        );
#       define d (*dd)

        for (
            int i = 0, j = 0; 
            i < bf; 
            i++, j++
        ) {
            if (i < tln)
                d.tl[j] = s[i];
            else {
                if (i == tln)
                    j = 0;
                
                d.rs[j] = s[i];
            }
        }
        
        d.tl[tln] = '\0';
        d.rs[rsn] = '\0';

#       undef d
        return dd;
    }

    static bool wr(_nn fl f, _nn ndp dd) {
#       define d (*dd)

        if (fwrite(d.tl, soc, tln, f) != tln)
            return 0;
        
        if (fwrite(d.rs, soc, rsn, f) != rsn)
            return 0;

#       undef d
        return 1;
    }

    _nd static int fs(_nn fl f) {
        int a = 0; char b = 0;
        while (fread(&b, soc, 1, f) == 1)
            a++;
        return a;
    }

    _nd static int ffs(_nn fl f)
    { return fs(f) / bf; }

    _nd static ndp _nl gt(_nn fl f, int p, bool b) {
        if (p < 0) return 0;
        
        int ps = p * (b ? bf : 1);
        if (fseek(f, ps, 0))
            return 0;
        
        return rd(f);
    }
};

///////////////////////////////

_sch(sr)

    _nd static ndp _nl src(_nn fl f, _nn ss tl) {
        int l = 0, r = fio::ffs(f)-1, m = 0;
        if (r < 0) return 0;

        while (l <= r) {
            int m = l + (r - l) / 2;
            
            ndp d = fio::gt(f, m, 1);
            if (!d) continue;

            if (!strcmp(d->tg, tl))
                return d;

            if (nd::cmt(tl, d->tg))
                l = m + 1;
            else
                r = m - 1;
        }
        return 0;
    }
};

///////////////////////////////

template<typename l, typename r>
struct pr final {
    l a;
    r b;

    pr(l a, r b) : a(a), b(b) {}
};
typedef pr<ss _nl, int> psi;
typedef psi* psp;

///////////////////////////////

_sch(tb)
private:
    inline static psp _nl ps;
    inline static int sz;

public:

    static void nt(_nn fl f) {
        sz = 0;
        ndp d = 0;

        while ((d = fio::rd(f))) {
            ps = (psp) 
                realloc(ps, (sz+1) * sizeof(psi));
            ps[sz] = psi(d->tl, sz * bf);
            sz++;
        }
    }

    _nd static int srd(_nn fl f, _nn ss tl) {
        int l = 0, r = sz, m = 0;
        if (r < 0) return 0;

        while (l <= r) {
            int m = l + (r - l) / 2;
            
            psi d = ps[m];

            if (!strcmp(d.a, tl))
                return d.b;

            if (nd::cmt(tl, d.a))
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};

///////////////////////////////

_sch(ts)

    [[deprecated, gnu::unused]]
    static void rnd(_nn fl f, int n) {
        srand(time(0));
        
        int i = 0, j = 0, k = 0;

        for (i = 1; i < n; i++) {
            ss 
                a = new char[tln],
                b = new char[rsn];
            
            a[0] = '0' + i;
            for (j = 1; j < tln; j++)
                sprintf(
                    &a[j], 
                    "%d", 
                    j + rand() % (10 - j) + 0);

            printf(" | %s\n", a);

            for(k = 0; k < rsn; k++)
                b[k] = 'a';

            fio::wr(f, new nd(a, b));
        }
    }

    static void gn(_nn fl f, int n) {
        for (int i = 1, j = 0; i <= n; i++) {
            ss
                a = new char[tln],
                b = new char[rsn];

            a[0] = '0' + i;
            for (j = 1; j < tln; j++)
                sprintf(&a[j], "%d", j);
            
            for (j = 0; j < rsn; j++)
                b[j] = 'a' + j;
            
            fio::wr(f, new nd(a, b));
        }
    }

    static void gnm(_nn fl f, int n) {
        for (int i = 1, j = 0; i <= n; i++) {
            ss
                a = new char[tln],
                b = new char[rsn];

            ss k = new char[tln];
            sprintf(k, "%d", i);
            int l = strlen(k), m = 0, n = l-1;
            
            for (j = 0, m = tln-1; j < tln; j++, m--, n--)
                a[m] = j < l ? k[n] : '0';
            a[tln] = '\0';

            //printf("%s %s\n", k, a);

            for (j = 0; j < rsn; j++)
                b[j] = 'b' + j;
            
            fio::wr(f, new nd(a, b));
        }
    }

    static void prt(_nn fl f) {
        ndp d = 0;
        while ((d = fio::rd(f)))
            printf("%s %s\n", d->tl, d->rs);
    }
};

void drt(_nn void (*a)(void)) {
    using namespace std;

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
    static fl f = fopen(fn, "wb");
    
#   if 0
    //ts::rnd(f, 10);
    ts::gn(f, 9);
    freopen(fn, "rb", f);
    ts::prt(f);

    rewind(f);
    ndp d = sr::src(f, (ss) "5123456");
    printf("\n%d\n", d == 0);
    printf("\n%s %s\n", d->tl, d->rs);

    rewind(f);
    tb::nt(f);
    ndp e = fio::gt(f, tb::srd(f, (ss) "4123456"), 0);
    printf("\n%s %s\n", e->tl, e->rs);
/*#   elseif 0
    const int n = 10000;

    ts::gnm(f, n);
    freopen(fn, "rb", f);

    static ndp g = 0;
    drt([]() {
        g = sr::src(f, (ss) "0009998");
    });
    printf("\n%s %s\n", g->tl, g->rs);*/
#   else
    const int n = 10000;

    ts::gnm(f, n);
    freopen(fn, "rb", f);
    tb::nt(f);

    static int g = 0;
    drt([]() {
        g = tb::srd(f, (ss) "0009998");
    });
    ndp d = fio::gt(f, g, 0);

    printf("\n%s %s\n", d->tl, d->rs);
#   endif

    fclose(f);
    return 0;
}
