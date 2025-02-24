
#include <cstdio>
#include <cstdlib>
#include <queue>
#include "../a.h"

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

/*struct ndh {
    char ch;
    unsigned fq;
    ndh* lf, * rg;

    ndh(char ch, unsigned fq) : ch(ch), fq(fq), lf(0), rg(0) {}
};

class hp {
public:
    const unsigned cpt;
    ndh** ar;
    unsigned sz = 0;
    static const unsigned mxhg = 10;
    const char* const str;
    int** ds;
    int* ls;

    explicit hp(const unsigned cpt, const char* const a, const unsigned* const b)
            : cpt(cpt), ar(new ndh*[cpt]), str(a), ds(new int*[cpt]), ls(new int[cpt])
    {
        for (unsigned i = 0; i < cpt; i++, sz++) {
            ar[i] = new ndh(a[i], b[i]);
            ds[i] = 0;
            ls[i] = 0;
        }
        bld();
    }

    ndh* operator[](const unsigned a) const { return ar[a]; }

    static void swp(ndh*& a, ndh*& b) {
        ndh* t = a;
        a = b;
        b = t;
    }

    void hpf(int dx) const {
        int sml = dx, lf = 2 * dx + 1, rg = lf + 1;

        if (lf < sz and ar[lf]->fq < ar[sml]->fq)
            sml = lf;

        if (rg < sz and ar[rg]->fq < ar[sml]->fq)
            sml = rg;

        if (sml != dx) {
            swp(ar[sml], ar[dx]);
            hpf(sml);
        }
    }

    ndh* mn() {
        ndh* a = ar[0];
        ar[0] = ar[sz - 1];
        sz--;
        hpf(0);
        return a;
    }

    void ins(ndh* a) {
        if (sz > cpt - 1) throw 1;

        sz++;
        int i = (int) sz - 1;

        while (i and a->fq < ar[(i - 1) / 2]->fq) {
            ar[i] = ar[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        ar[i] = a;
    }

    void bld() const
    { for (
          int n = (int) sz - 1, i = (n - 1) / 2;
          i >= 0;
          hpf(i), i--
      ); }

    static bool ilf(ndh* a) { return !a->lf and !a->rg; }

    ndh* bht() {
        ndh* lf, * rg, * tp;
        while (sz != 1) {
            lf = mn();
            rg = mn();

            tp = new ndh(-1, lf->fq + rg->fq);
            tp->lf = lf;
            tp->rg = rg;

            ins(tp);
        }
        return mn();
    }

    void cds(ndh* rt, int* arr = new int[mxhg], const int tp = 0) {
        if (rt->lf) {
            arr[tp] = 0;
            cds(rt->lf, arr, tp + 1);
        }
        if (rt->rg) {
            arr[tp] = 1;
            cds(rt->rg, arr, tp + 1);
        }
        if (ilf(rt)) {
            printf("%c : ", rt->ch);

            int a = -1;
            for (unsigned i = 0; i < cpt; i++)
                if (str[i] == rt->ch)
                    a = (int) i;

            if (a >= 0) {
                ds[a] = new int[tp];
                ls[a] = tp;
            }

            for (unsigned i = 0; i < tp; i++) {
                printf("%d", arr[i]);

                if (a >= 0 and ds[a])
                    ds[a][i] = arr[i];
            }
            printf("\n");
        }
    }
};*/

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
    FILE* c = fopen("/home/admin/CLionProjects/structs/tsk6/a.txt", "r");
    for (char d; (d = (char) fgetc(c)) != EOF;)
        b.dd(d);
    fclose(c);
}

void wr(arr<unsigned char>& b) {
    FILE* a = fopen("/home/admin/CLionProjects/structs/tsk6/b.bin", "wb");
    for (unsigned i = 0; i < b.sz; i++) {
        printf("%d", b[i]);
        if (i > 0 and (i + 1) % 8 == 0)
            printf(" ");
    }
    printf("\n");

    unsigned i = 0, k = 0;
    int j = 7;
    for (; i < b.sz;) {
        if (j < 0) {
            fwrite(&k, 1, 1, a);
            printf("%d ", k);
            j = 7, k = 0;
        } else
            k |= b[i++] << j--;
    }
    printf("\n");
    fclose(a);
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

//    for (unsigned i = 0; i < (int) m - 1; i++)
//        for (unsigned j = 0; j < (int) m - (int) i - 1; j++)
//            if (c[j] > c[j + 1]) {
//                { unsigned t = c[j];
//                    c[j] = c[j + 1];
//                    c[j + 1] = t; }
//                { char t = e[j];
//                    e[j] = e[j + 1];
//                    e[j + 1] = t; }
//            }

    for (unsigned i = 0; i < m; i++)
        printf("%3c ", e[i]);
    printf("\n");

    for (unsigned i = 0; i < m; i++) {
        c[i] = (int) (((float) c[i] / (float) b) * 1000);
        printf("%3d ", c[i]);
    }
    printf("\n");

//    hp d(m, e, c);
//    auto _a = d.bht();
//    d.cds(_a);

    arr<char> ls;
    arr<arr<char>*> ds;
    arr<char> str;
    gen(e, c, m, ls, ds, str);

    printf("\n");

    arr<unsigned char> h;
    for (unsigned j = 0; j < m /*d.cpt*/; j++) {
        atb0(h, /*d.*/ str[j]);

        arr<unsigned char> _t;
        atb0(_t, /*d.*/ str[j]);
        for (unsigned k = 0; k < _t.sz; k++)
            printf("%d", _t[k]);
        printf(" - %c ", /*d.*/ str[j]);

        for (unsigned k = 0; k < /*d.*/ ls[j]; k++)
            printf("%d", /*d.*/ ds[j]->ar[k]), h.dd(/*d.*/ ds[j]->ar[k]);
        printf("\n");

        if (j == m /*d.cpt*/ - 1) atb0(h, 0xFF);
    }

    for (unsigned i = 0; i < b; i++)
        for (unsigned j = 0; j < m /*d.cpt*/; j++)
            if (a[i] == /*d.*/ str[j])
                for (unsigned k = 0; k < /*d.*/ls[j]; k++)
                    h.dd(/*d.*/ds[j]->ar[k]);
    wr(h);
}

