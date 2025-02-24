
#include <cstdio>
#include <cstdlib>
#include <queue>
#include "a.h"

template<typename T>
class arr {
public:
    const int sot = sizeof(T);
    T *ar = 0;
    unsigned sz = 0;

    ~arr() { delete[] ar; }

    auto dd(T a) {
        ar = (T *) realloc(ar, sot * ++sz);
        ar[sz - 1] = a;
        return this;
    }

    T operator[](const unsigned a) { return ar[a]; }

    auto cpy() {
        auto b = new arr<T>();
        for (int i = 0; i < sz; i++)
            b->dd(ar[i]);
        return b;
    }
};

struct ndh {
    char ch;
    unsigned fq;
    ndh* lf;
    ndh* rg;

    ndh(char dt, unsigned fq) : ch(dt), fq(fq), lf(0), rg(0) {}
    ~ndh() { delete lf, delete rg; }
};

void prt(
    ndh* rt,
    arr<char>* cd,
    arr<char>& ls,
    arr<arr<char>*>& ds,
    arr<char>& str
) {
    if (!rt) return;

    if (rt->ch == -1) {
        prt(rt->lf, cd->cpy()->dd(0), ls, ds, str);
        prt(rt->rg, cd->cpy()->dd(1), ls, ds, str);
    }

    if (rt->ch != -1) {
        printf("%c : ", rt->ch);

        for (unsigned i = 0; i < cd->sz; i++)
            printf("%d", cd->ar[i]);
        printf("\n");

        ls.dd((char) cd->sz);
        ds.dd(cd->cpy());
        str.dd(rt->ch);

        prt(rt->lf, cd->cpy()->dd(0), ls, ds, str);
        prt(rt->rg, cd->cpy()->dd(1), ls, ds, str);
    }
}

void gen(
    const char* dt,
    const unsigned* fqs,
    unsigned ln,
    arr<char>& ls,
    arr<arr<char>*>& ds,
    arr<char>& str
) {
    using namespace std;

    ndh* lf;
    ndh* rg;

    auto cmp = [](ndh* l, ndh* r) { return l->fq > r->fq; };
    priority_queue<ndh*, vector<ndh*>, decltype(cmp)> mnhp(cmp);

    for (size_t i = 0; i < ln; ++i)
        mnhp.push(new ndh(dt[i], fqs[i]));

    ndh* tp = 0;
    while (mnhp.size() != 1) {
        lf = mnhp.top();
        mnhp.pop();

        rg = mnhp.top();
        mnhp.pop();

        tp = new ndh(-1, lf->fq + rg->fq);
        tp->lf = lf;
        tp->rg = rg;
        mnhp.push(tp);
    }

    prt(mnhp.top(), new arr<char>(), ls, ds, str);
}

void rd(arr<char>& b) {
    FILE* c = fopen("a.txt", "r");
    for (char d; (d = (char) fgetc(c)) != EOF;)
        b.dd(d);
    fclose(c);
}

void atb0(arr<unsigned char>& st, unsigned char n) {
    unsigned char abt[8] = { 0 };
    char j = 7;
    while (n > 0) {
        abt[j--] = n % 2;
        n /= 2;
    }
    for (unsigned char _i : abt)
        st.dd(_i);
}

void wr(FILE* a, arr<unsigned char>& b, unsigned char ln) {
    unsigned i = 0;
    for (; i < b.sz; i++) {
        printf("%d", b[i]);
        if (i > 0 and (i + 1) % 8 == 0)
            printf(" ");
    }
    printf("\n## %d\n", i), fwrite(&ln, 1, 1, a);

    i = 0; unsigned char k = 0; int j = 7;
    for (; i < b.sz;) {
        if (j < 0) {
            fwrite(&k, 1, 1, a);

            arr<unsigned char> _t;
            atb0(_t, k);
            for (unsigned _i = 0; _i < _t.sz; _i++)
                printf("%d", _t[_i]);
            printf(" ");

            j = 7, k = 0;
        } else
            k |= b[i++] << j--;
    }
    fwrite(&k, 1, 1, a), printf("%d\n", k);
}

void lnch() {
    arr<char> a;
    rd(a);
    const unsigned b = a.sz;

    bool* l = new bool[b]();
    unsigned m = 0;
    char* e = 0;

    for (unsigned i = 0; i < b; i++) {
        for (unsigned j = 0; j < b; j++)
            if (i != j and a[i] == a[j])
                l[j] = 1;

        if (l[i]) continue;

        e = (char*) realloc(e, ++m);
        e[m - 1] = a[i];
    }

    for (unsigned i = 0; i < m; i++)
        printf("%c ", e[i]);
    printf("\n");

    auto c = new unsigned[m]();

    for (unsigned i = 0; i < m; i++)
        for (unsigned j = 0; j < b; j++)
            if (e[i] == a[j])
                c[i]++;

    for (unsigned i = 0; i < m; i++)
        printf("%d ", c[i]);
    printf("\n");

    for (unsigned i = 0; i < m; i++)
        printf("%3c ", e[i]);
    printf("\n");

    for (unsigned i = 0; i < m; i++) {
        c[i] = (int) (((float) c[i] / (float) b) * 1000);
        printf("%3d ", c[i]);
    }
    printf("\n");

    arr<char> ls;
    arr<arr<char>*> ds;
    arr<char> str;
    gen(e, c, m, ls, ds, str);

    printf("\n");

    arr<unsigned char> h;
    for (unsigned j = 0; j < m; j++) {
        atb0(h, str[j]);

        arr<unsigned char> _t;
        atb0(_t, str[j]);
        for (unsigned k = 0; k < _t.sz; k++)
            printf("%d", _t[k]);
        printf(" - %c ", str[j]);

        for (unsigned k = 0; k < ls[j]; k++)
            printf("%d", ds[j]->ar[k]), h.dd(ds[j]->ar[k]);
        printf("\n");

        if (j == m - 1) atb0(h, 0xFF);
    }

    unsigned char log = 0;
    for (unsigned i = 0; i < b; i++)
        for (unsigned j = 0; j < m; j++)
            if (a[i] == str[j])
                for (unsigned k = 0; k < ls[j]; k++)
                    h.dd(ds[j]->ar[k]),
                    log++;
    wr(fopen("b.bin", "wb"), h, log);
}
