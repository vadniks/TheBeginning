
#include <iostream>
#include <cstring>
#include <vector>

#define ths (*this)
#define _r(_x) { return _x; }

#ifdef __GNUC__
#    define _nn [[gnu::nonnull]]
#else
#    define _nn
#endif

#ifdef __clang__
#    define _nl _Nullable
#else
#    define _nl
#endif

#define _nd [[nodiscard]]

typedef char* ss;
typedef const char* cs;

using namespace std;

const int bf = 16;

/////////////////////////////////////////

class cl {
protected:
    cs nm = 0;
    cl* hd;
    vector<cl*> cls;

public:
    
    cl(_nn cs nm, cl* _nl hd) : 
        nm(nm), 
        hd(hd), 
        cls(vector<cl*>())
    {}
    
    ~cl() = default;

    _nd _nn cs gnm() _r(nm)
    _nd cl* _nl ghd() _r(hd)
    _nd _nn cl** gcls() _r(cls.data())
    _nd int gsz() _r(cls.size())
    
    void dd(_nn cl* a)
    { cls.push_back(a); }

    _nd cl* _nl wlk(_nn ss a) {
        if (!strcmp(ths.nm, a))
            return this;
        
        cl** cls = ths.gcls();
        int sz = ths.gsz();

        cl* r = 0;
        for (int i = 0; !r and i < sz; i++)
            r = cls[i]->wlk(a);
        
        return r;
    }

    void prt() {
        cl** cls = ths.gcls();
        int sz = ths.gsz();

        for (int i = 0; i < sz; i++) {
            if (!i) cout << endl << ths.nm;
            cout << "  " << cls[i]->nm;
        }

        for (int i = 0; i < sz; i++)
            cls[i]->prt();
    }
};

/////////////////////////////////////////

class apl : public cl {
public:

    apl() : cl("apl", 0) {}

    _nd _nn cl* trc() {
        ss rt = new char[bf];
        cin >> rt;

        return new cl(rt, 0);
    }

    void rn() {
        cl krn = *trc();

        ss hd, sj;
        while(1) {
            hd = new char[bf], 
            sj = new char[bf];

            cin >> hd >> sj;
            if (!strcmp(hd, sj)) break;

            cl* hhd = krn.wlk(hd);
            if (!hhd) throw 1;

            hhd->dd(new cl(sj, hhd));
        }
        cout << krn.gnm();
        krn.prt();
    }
};

/////////////////////////////////////////

int main() {
    apl ap;
    ap.rn();
    return 0;
}
