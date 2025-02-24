/*
                         .-''-.     
 .----.     .----.     .' .-.  )    
  \    \   /    /     / .'  / /     
   '   '. /'   /     (_/   / /      
   |    |'    /           / /       
   |    ||    |          / /        
   '.   `'   .'         . '         
    \        /         / /    _.-') 
     \      /        .' '  _.'.-''  
      '----'        /  /.-'_.'      
                   /    _.'         
                  ( _.-'            
*/

/*       _               _              _      
        /\ \           /\ \           /\ \     
       /  \ \         /  \ \         /  \ \    
      / /\ \_\       / /\ \ \       / /\ \ \   
     / / /\/_/      / / /\ \ \     / / /\ \ \  
    / / / ______   / / /  \ \_\   / / /  \ \_\ 
   / / / /\_____\ / / /    \/_/  / / /    \/_/ 
  / / /  \/____ // / /          / / /          
 / / /_____/ / // / /________  / / /________   
/ / /______\/ // / /_________\/ / /_________\  
\/___________/ \/____________/\/____________/  
*/

#include <cstdio>

#define _nn [[gnu::nonnull]]
#define _nl _Nullable
#define _nd [[nodiscard]]

typedef int* inp;

////////////////////////////////

class vl {
public:
    static const int 
        vln = 7,
        vlf = 3;

    /*_nn*/ inp 
        vla,
        vlb;
    int tm;

    vl(_nn inp a, _nn inp b, int t) :
        vla(a), vlb(b), tm(t)
    {}

    void pr() {
        for (int i = 0; i < vlf; i++) {
            for (int j = 0; j < (i < 2 ? vln : 0); j++)
                printf("%d", !i ? vla[j] : vlb[j]);
            
            if (i == 2)
                printf("%d", tm);
            printf("\n");
        }
        printf("\n");
    }

    _nd static bool cmp(_nn vl* a, _nn vl* b) {
        const int g = 4;

        bool c = 1;
        int
            d = 0, 
            e = 0;

        for (int i = 0; i < g; i++) {
            d *= !i ? 1 : 10, d += a->vla[i];
            e *= !i ? 1 : 10, e += b->vla[i];
        }

        return d >= e;
    }

    _nd bool aq(_nn inp a) {
        bool b = 1;

        for (int i = 0; i < vln; i++)
            b &= a[i] == vla[i];

        return b;
    }
};
typedef vl* vlp;

////////////////////////////////

struct nd {
    /*_nn*/ vlp vl;

    nd 
        *_nl nx,
        *_nl pr;
};
typedef nd* ndp;

////////////////////////////////

class lst {
public:
    int     sz = 0;
    ndp _nl fs = 0;
    ndp _nl ls = 0;

    lst() {}

    lst(int sz, _nn ndp fs, _nn ndp ls) :
        sz(sz), fs(fs), ls(ls)
    {}

    _nn virtual ndp dd(_nn vlp vl) {
        ndp d = new nd();
        d->vl = vl;
        d->nx = 0;
        d->pr = ls;

        if (ls) ls->nx = d;
        if (!sz) fs = d;
        
        ls = d;
        sz++;
        return d;
    }

    _nd ndp _nl sr(_nn vlp a) {
        ndp b = fs;
        if (!b) return 0;

        while (b) {
            if (a == b->vl)
                return b;
            b = b->nx;
        }
        return 0;
    }

    virtual bool dl(_nn vlp a) {
        ndp b = 
            sr(a),
            c = 0, 
            d = 0;

        if (!b) return 0;

        c = b->pr, d = b->nx;
        if (c) c->nx = d;
        if (d) d->pr = c;
        
        if (b == fs) fs = d;
        if (b == ls) ls = c;

        delete b;
        return 1;
    }

    void prt(bool a) {
        ndp d = !a ? fs : ls;
        while (d) {
            d->vl->pr();
            d = !a ? d->nx : d->pr;
        }
    }
};

////////////////////////////////

class lsd final : public lst {
public:
    
    lsd(_nn lst* a) :
        lst(a->sz, a->fs, a->ls)
    {}

    _nn ndp dd(_nn vlp a) override {
        ndp b = lst::dd(a);
        srt();
        return b;
    }

    void srt() {
        if (!fs) return;

        bool sw;
        ndp a = 0, b = 0;
        vlp t = 0;
    
        do {
            sw = 0;
            a = fs;
    
            while (a->nx != b) {
                if (vl::cmp(a->vl, a->nx->vl)) {
                    t = a->vl;
                    a->vl = a->nx->vl;
                    a->nx->vl = t;

                    sw = 1;
                }
                a = a->nx;
            }
            b = a;
        } while (sw);
    }

    bool dl(_nn inp a) {
        ndp b = fs, c = 0;

        while (b) {
            if (b->vl->aq(a))
                c = b;
            b = b->nx;
        }

        return lst::dl(c->vl);
    }

    _nd int sm(_nn inp a) {
        int s = 0;

        ndp b = fs;
        while (b) {
            vlp c = b->vl;
            if (c->aq(a))
                s += c->tm;
            b = b->nx;
        }

        return s;
    }
};

////////////////////////////////

int main() {
    lst a;

#   define inpd (int[]) {

    const int vll = 6;
    vlp b[vll] = { 
        new vl(
            inpd 6, 4, 0, 4, 5, 1, 2 }, 
            inpd 4, 5, 1, 0, 7, 6, 0 },
            6),
        new vl(
            inpd 1, 2, 3, 4, 5, 6, 7 }, 
            inpd 7, 6, 5, 4, 3, 2, 1 },
            1),
        new vl(
            inpd 1, 5, 9, 7, 6, 8, 2 }, 
            inpd 9, 6, 5, 8, 1, 6, 1 },
            2),
        new vl(
            inpd 9, 8, 6, 5, 7, 1, 8 }, 
            inpd 8, 7, 6, 8, 2, 3, 5 },
            4),
        new vl(
            inpd 4, 8, 6, 5, 7, 1, 8 }, 
            inpd 8, 7, 6, 8, 2, 3, 5 },
            3),
        new vl(
            inpd 6, 4, 0, 4, 5, 1, 2 }, 
            inpd 4, 5, 1, 0, 7, 6, 0 },
            5),
    };

    for (int i = 0; i < vll; i++)
        a.dd(b[i]);
    a.prt(0);

    printf("------\n");
    
    lsd c(&a);
    
    /*c.dd(new vl(
        inpd 7, 0, 0, 9, 1, 6, 1 },
        inpd 1, 0, 1, 2, 3, 4, 5 },
        6)
    );*/

    //c.dl(inpd 6, 4, 0, 4, 5, 1, 2 });
    printf("%d\n", c.sm(inpd 6, 4, 0, 4, 5, 1, 2 }));
    c.prt(0);

    return 0;
}
