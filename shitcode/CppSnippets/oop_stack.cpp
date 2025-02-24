
//////////////////////////////////

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define _g(_x) { return _x; }

using namespace std;

typedef char* cs;
typedef const char* ccs;
typedef const int ci;

//////////////////////////////////

template<typename L, typename R>
struct pr {
    L l;
    R r;

    pr(L _l, R _r) : 
        l(_l), r(_r) {}

    ~pr() = default;
};

typedef pr<int, bool> prib;

cs itoa(int i) {
    cs a = (cs) calloc(16, sizeof(char));
    snprintf(a, 16, "%d", i);
    return a;
}

//////////////////////////////////

class St {

private:
    ccs nm;
    ci lg;
    ci mxsz;
    int sz;
    int* a;
    bool o;

public:

    St(ccs _nm, ci _lg) :
        nm(_nm),
        lg(_lg),
        mxsz(_lg-1),
        sz(0),
        a((int*) calloc(_lg, sizeof(int))),
        o(0) 
    {}

    ~St() = default;

    bool psh(int e) {
        if (sz > mxsz) 
            return 0;
        
        a[sz] = e;
        sz++;
        
        return 1;
    }

    prib pp() {
        sz--;
        
        if (sz < 0) 
            return prib(0, 0);
        
        prib r = prib(a[sz], 1);
        a[sz] = 0;
        
        return r;
    }

    ccs gnm() _g(nm)
    ci glg() _g(lg)
    ci gsz() _g(sz)
};

//////////////////////////////////

int main() {
    char aa[16] = { 0 };
    char bb[16] = { 0 };
    int al = 0, bl = 0;
    
    scanf("%s %d\n", aa, &al);
    scanf("%s %d\n", bb, &bl);

    ci bf = 256;
    char ss[bf] = { 0 };

    fgets(ss, bf, stdin);

    St ast(aa, al);
    St bst(bb, bl);

    cs tk = 0;
    tk = strtok(ss, " ");
    while (tk != 0) {
        int n = atoi(tk);
        tk = strtok(0, " ");
        
        if (!ast.psh(n))
            break;
        if (!bst.psh(n))
            break;
    }

    printf("%s %d\n%s %d\n", aa, al, bb, bl);
    printf("%-15s%-15s\n", aa, bb);

    int ni = (al > bl) ? al : bl;
    for (int i = 0; i < ni; i++) {
        prib ap = ast.pp(), bp = bst.pp();

        if (ap.r || bp.r) {
			if (i > 0) printf("\n");
			printf("%15s", (ap.r) ? itoa(ap.l) : " ");

			if (bp.r)
				printf("%15s", itoa(bp.l));
		}
    }

    return 0;
}

//////////////////////////////////
