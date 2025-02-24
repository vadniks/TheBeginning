
#include <iostream>
#include <cstring>
#include <vector>

#define ths    (*this)
#define _r(_x) { return _x; }

///////////////////////////////

#if defined(__GNUC__)
#  if __cplusplus >= 201703L
#    define _nn [[gnu::nonnull]]
#  else
#    define _nn __attribute__((nonnull))
#  endif
#else
#  define _nn
#endif

#if defined(__clang__)
#  define _nl _Nullable
#else
#  define _nl
#endif

#if __cplusplus >= 201103L
#  define _nd [[nodiscard]]
#else
#  define _nd
#endif

///////////////////////////////

typedef char*       ss;
typedef const char* cs;

using namespace std;

const int bf = 16;

///////////////////////////////

/*abstract*/ class cl {
protected:
	cs          nm;
	cl*         hd;
	vector<cl*> cls;
    int         rd;

public:

	cl(
        cl* _nl hd, 
        cs _nl nm = 0,
        int rd = 0
    ) : 
        nm(nm ? nm : ""), 
        hd(hd), 
        cls(vector<cl*>()),
        rd(rd)
    {}

	~cl() = default;

	_nd _nn         cs       gnm()  _r(nm)
    _nd             cl*  _nl ghd()  _r(hd)
    _nd _nn         cl**     gcls() _r(cls.data())
    _nd             int      gsz()  _r(cls.size())
    _nd     virtual int      gn()   = 0;
    _nd             int      grd()  _r(rd)
    _nd             bool     rdd()  _r(rd > 0)

	void dd(_nn cl* a)
    { cls.push_back(a); }

	_nd cl* _nl wlk(_nn ss a)  {
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
            cout << endl;
            cout << "The object " << cls[i]->nm << " is " <<
                (cls[i]->rdd() ? "" : "not ") << "ready";
        }

        for (int i = 0; i < sz; i++)
            cls[i]->prt();
    }

	void snm(_nn cs _nm) 
    { nm = _nm; }

    void shd(cl* _nl _hd)
    { hd = _hd; }

    void srd(int _rd)
    { rd = _rd; }
};

///////////////////////////////

class aa final : public cl {
public:

	aa(_nn cl* hd, _nn cs nm, int rd) :
		cl(hd, nm, rd)
	{}
	
	~aa() = default;

    _nd int gn() override _r(2)
};

///////////////////////////////

class bb final : public cl {
public:

	bb(_nn cl* hd, _nn cs nm, int rd) :
		cl(hd, nm, rd)
	{}
	
	~bb() = default;

    _nd int gn() override _r(3)
};

///////////////////////////////

class cc final : public cl {
public:

	cc(_nn cl* hd, _nn cs nm, int rd) :
		cl(hd, nm, rd)
	{}
	
	~cc() = default;

    _nd int gn() override _r(4)
};

///////////////////////////////

class apl final : public cl {
public:

	apl() : cl(0, "apl", 1) {}
	~apl() = default;

    _nd int gn() override _r(1)

    _nd _nn cl* frt(
        int _n, 
        _nn cl* hd, 
        _nn cs nm, 
        int rd
    ) { 
        if (_n == 1)
            throw 1;
        else if (_n == 2)
            return new aa(hd, nm, rd);
        else if (_n == 3)
            return new bb(hd, nm, rd);
        else if (_n == 4)
            return new cc(hd, nm, rd);
        else
            throw 2;
    }

	_nd _nn apl* trc()  {
        ss rt = new char[bf];
        cin >> rt;

        snm(rt);
        shd(0);
        srd(1);
        return this;
    }

	void rn()  {
        apl krn = *trc();

        ss hd, sj;
        int n = 0, rd = 0;
        
        while(1) {
            hd = new char[bf], 
            sj = new char[bf];

            cin >> hd;
            if (!strcmp(hd, "endtree")) break;
            cin >> sj >> n >> rd;

            cl* hhd = krn.wlk(hd);
            if (!hhd) throw 1;

            hhd->dd(frt(n, hhd, sj, rd));
        }
        cout << "Test Result";
        krn.prt();
    }
};

///////////////////////////////

int main() {
	apl ap;
	ap.rn();
	/* trc() is built-in */
	return 0;
}
