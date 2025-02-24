/*
        ,-.-. ,-----,--,   
 ,--.-./=/ ,/ | '-  -\==\  
/==/, ||=| -| \,--, '/==/  
\==\,  \ / ,|    /  /==/   
 \==\ - ' - /   / -/==/    
  \==\ ,   |   / -/==/     
  |==| -  ,/  / `\==\_,--, 
  \==\  _ /  /` -   ,/==/  
   `--`--'   `------`--`   
      ___          ___          ___     
     /\  \        /\  \        /\  \    
    /::\  \      /::\  \      /::\  \   
   /:/\:\  \    /:/\:\  \    /:/\:\  \  
  /:/  \:\  \  /:/  \:\  \  /:/  \:\  \ 
 /:/__/_\:\__\/:/__/ \:\__\/:/__/ \:\__\
 \:\  /\ \/__/\:\  \  \/__/\:\  \  \/__/
  \:\ \:\__\   \:\  \       \:\  \      
   \:\/:/  /    \:\  \       \:\  \     
    \::/  /      \:\__\       \:\__\    
     \/__/        \/__/        \/__/    
*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>

#define _nl _Nullable
#define _nn [[gnu::nonnull]]
#define _nd [[nodiscard]]

#define nnn != 0
#define _r(_x) { return _x; }

/////////////////////////////////////

struct nd {
    float vl;
    nd* _nl nx;
};
typedef nd* ndp;

class lst {
private:
    int sz;
    ndp ls;

public:
    ndp fs;

    lst() :
        sz(0),
        ls(0),
        fs(0)
    {}

/* aka infix functions protos */
#   define mp mp()
#   define gtl gtl()
#   define lng lng()

    _nd bool mp _r(!sz)
    _nd ndp _nl gtl _r(ls)
    _nd int lng _r(sz)

    _nn ndp nsrt(float vl) {
        ndp d = new nd();
        d->vl = vl;
        d->nx = 0;

        if (ls nnn) ls->nx = d;
        if (mp) fs = d;

        ls = d;
        sz++;

        return d;
    }

    void dl(float vl) {
        ndp d = fs;
        if (!d) return;
        
        if (d->vl == vl) {
            fs = d->nx;
            delete d;
            return;
        }

        ndp e = d->nx;
        while (d nnn and e nnn and e->vl != vl) {
            d = d->nx;
            e = e->nx;
        }
        d->nx = !e ? e : e->nx;
        delete e;
    }

    void prt() {
        if (mp) throw 1;

        ndp d = fs;
        while (d != 0) {
            printf("%g\n", d->vl);
            d = d->nx;
        }
    }
};
typedef lst* lsp;

/////////////////////////////////////

_nd _nn lsp _nl smt(_nn lsp a, _nn lsp b) {
    lsp c = new lst();
    ndp da = a->fs;
    ndp db = b->fs;
    
    int i = 0;
    while (da nnn and db nnn) {
        if (da->vl == db->vl)
            c->nsrt(da->vl);
        
        da = da->nx;
        db = db->nx;
        i++;
    }
    return c;
}

void dbn(_nn lst* a) {
    if (!a->lng) throw 1;

    ndp d = a->fs, e = 0;
    while (d nnn) {
        e = d->nx;
        
        if (d->nx nnn and d->nx->vl < 0.0f)
            a->dl(d->vl);

        d = e;
    }
}

void nbo(_nn lst* a, float b) {
    if (!a->lng) throw 1;

    ndp d = a->fs, f = 0, g = 0, e = 0;
    if (!d) return;

    if (fmodf(d->vl, 2.0f) nnn) {
        g = new nd();
        g->vl = b;
        g->nx = d;

        a->fs = g;
    }

    while (d nnn) {
        f = d->nx;

        if (d != e and f nnn and fmodf(f->vl, 2.0f) nnn) {
            g = new nd();
            g->vl = b;
            g->nx = f;

            d->nx = g;
            e = g;
        }

        d = d->nx;
    }
}
/* insert */
/////////////////////////////////////

int main() {
    lst a;

    a.nsrt(2.0);
    a.nsrt(5.1);
    a.nsrt(-6.0);
    a.nsrt(4.1);
    a.nsrt(6.0);

    a.prt();
    printf("\n");
    nbo(&a, 11.5);
    printf("\n");
    a.prt();

    return 0;
}
