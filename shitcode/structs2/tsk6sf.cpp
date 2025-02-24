
// variant 17

#pragma ide diagnostic ignored "modernize-use-nullptr"
#pragma ide diagnostic ignored "modernize-use-bool-literals"
#pragma ide diagnostic ignored "bugprone-reserved-identifier"
#pragma ide diagnostic ignored "cert-flp30-c"

#include <cstdlib>
#include <cstdio>
#include "../a.h"

using namespace std;

typedef unsigned int unt;

template<typename A, typename B>
struct pr {
    A a;
    B b;

    pr(A a, B b) : a(a), b(b) {}
    pr() = default;

    bool operator==(pr<A, B>& c) { return a == b; }
};

template<typename T>
class arr {
    typedef arr<T> *art;
public:
    const int sot = sizeof(T);
    T *ar = 0;
    int sz = 0;

    ~arr() { delete[] ar; }

    art dd(const T a) {
        ar = (T *) realloc(ar, sot * ++sz);
        ar[sz - 1] = a;
        return this;
    }

    T operator[](const unt a) { return ar[a]; }
};

template<typename K, typename V>
class map {
    typedef pr<K, V> T;
public:
    arr<T*> ar;

    V& operator[](const K& a) {
        for (int i = 0; i < ar.sz; i++)
            if (ar[i]->a == a)
                return ar[i]->b;

        ar.dd(new pr(a, V()));
        return ar[ar.sz - 1]->b;
    }

    T& operator[](const unt a) { return *ar[a]; }

    unt sz() { return ar.sz; }
};

typedef unsigned char bt;
typedef pr<char, float> pcf;
typedef map<char, arr<char>> mca;

void enc(int c, int d, arr<pcf>& ar, mca& cds) {
    if (c == d)
        return;
    else if (d - c == 1) {
        cds[ar[c].a].dd('0');
        cds[ar[d].a].dd('1');
        return;
    }

    float pbs = 0;
    int i, k = -1;

    for (i = c; i <= d; i++)
        pbs += ar[i].b;

    float ph = pbs * 0.5f, p = 0;
    for (i = c; i <= d; i++) {
        p += ar[i].b;
        cds[ar[i].a].dd(p <= ph ? '0' : '1');

        if (p > ph && k < 0)
            k = i;
    }
    if (k < 0) k = c + 1;

    enc(c, k - 1, ar, cds);
    enc(k, d, ar, cds);
}

void atb(arr<unsigned char>& st, unsigned char n) {
    unsigned char abt[8] = { 0 };
    char j = 7;
    while (n > 0) {
        abt[j--] = n % 2;
        n /= 2;
    }
    for (unsigned char _i : abt)
        st.dd(_i);
}

void wr(FILE* a, arr<unsigned char>& b, unsigned char ln, unsigned char nts) {
    unsigned i = 0;
    for (; i < b.sz; i++) {
        printf("%d", b[i]);
        if (i > 0 and (i + 1) % 8 == 0)
            printf(" ");
    }
    printf("\n## %d %u\n", i, ln);

    fwrite(&ln, 1, 1, a);
    fwrite(&nts, 1, 1, a);

    i = 0;
    unsigned char k = 0;
    int j = 7;
    for (; i < b.sz;) {
        if (j < 0) {
            fwrite(&k, 1, 1, a);

            arr<unsigned char> _t;
            atb(_t, k);
            for (unsigned _i = 0; _i < _t.sz; _i++)
                printf("%d", _t[_i]);
            printf(" ");

            j = 7, k = 0;
        } else
            k |= b[i++] << j--;
    }
    fwrite(&k, 1, 1, a);
    printf("@%d\n", k);
}

unsigned char shfn(FILE* in, arr<unsigned char>& out, unsigned char& nts) {
    arr<char> txt;
    map<char, unt> frs;

    float ln = 0;
    for (char c = -1; (c = (char) fgetc(in)) != EOF; ln++) {
        printf("%c", c);
        txt.dd(c);
        frs[c]++;
    }
    printf("\n");

    arr<pcf> ar;
    for (unt i = 0; i < frs.sz(); i++) {
        printf("%c %u ", frs[i].a, frs[i].b);
        ar.dd(pr(frs[i].a, float(frs[i].b) / float(ln)));

        arr<unsigned char> _t;
        atb(_t, frs[i].a);
        for (unsigned _i = 0; _i < _t.sz; _i++)
            printf("%d", _t[_i]);
        printf("\n");
    }

    qsort(ar.ar, ar.sz, sizeof(pcf), [](const void* _a, const void* _b) {
        float __a = ((pcf*) _a)->b;
        float __b = ((pcf*) _b)->b;
        return __a < __b ? 1 : __a > __b ? -1 : 0;
    });

    mca cds;
    enc(0, ar.sz - 1, ar, cds);

    for (int i = 0; i < ar.sz; i++) {
        atb(out, ar[i].a);

        printf("%c ", ar[i].a/*, ar[i].b*/);

        auto& c = cds[ar[i].a];
        if (c.sz > 8) throw 1;
        atb(out, c.sz);
        nts += 8 * 2;
//        printf("%d ", c.sz);
        for (unt j = 0, k = c.sz - 1; j < c.sz; j++, k--) {
            nts++;
            printf("%c", c[j]);
            out.dd(c[j] == '1');
        }
        printf("\n");
    }
    printf("\n");

    unt k = 0, lg = 0;
    for (char c = txt[0]; k < txt.sz; k++, c = txt[k]) {
        for (unt i = 0; i < cds[c].sz; i++)
            out.dd(cds[c][i] == '1'), printf("%c", cds[c][i]), lg++;
    }
    printf("\n");
    if (lg > 0xFF) throw 1;
    return lg;
}

bool eql(arr<unsigned char>* a, arr<unsigned char>* b) {
    if (a->sz != b->sz) return 0;
    for (int i = 0; i < a->sz; i++)
        if (a->ar[i] != b->ar[i])
            return 0;
    return 1;
}

void shfn2(arr<unsigned char>* lts, arr<arr<unsigned char>*>* cds, arr<unsigned char>* arc, FILE* out) {
    arr<unsigned char> a;
    for (int i = 0; i < arc->sz; i++) {
        a.dd(arc->ar[i]);

        for (int j = 0; j < cds->sz; j++)
            if (eql(cds->ar[j], &a)) {
                a.sz = 0, delete[] a.ar, a.ar = 0;
                auto _a = lts->ar[j];
                fwrite(&_a, 1, 1, out);
            }
    }
}

void lnch() {
    // text text text text
    FILE* in = fopen("/home/admin/CLionProjects/structs/tsk6/a.txt", "r");
    arr<unsigned char> st;

    unsigned char nts = 0;
    auto log = shfn(in, st, nts);
    fclose(in);

    FILE* out = fopen("/home/admin/CLionProjects/structs/tsk6/b.bin", "wb");
    wr(out, st, log, nts);
    delete[] st.ar, st.ar = 0, st.sz = 0;

    freopen("/home/admin/CLionProjects/structs/tsk6/b.bin", "rb", out);

    arr<unsigned char> dt;

    int _c = -1;
    unsigned char a = 0, ln = 0, nts2 = 0;
    while (fread(&a, 1, 1, out) == 1) {
        if (!ln) { ln = a; continue; }
        if (_c < 0) { nts2 = a; _c++; continue; }
        _c++;
        atb(dt, a);
    }
    printf("# %d %d %d\n", _c, ln, nts2);
    fclose(out);

    auto arc = new arr<unsigned char>();
    for (unsigned i = nts2; i < ln + nts2 and dt.sz; i++)
        arc->dd(dt[i]);

    if (dt.sz > nts2)
        dt.ar = (unsigned char*) realloc(dt.ar, (unsigned) nts2),
        dt.sz = nts2;

    auto cds = new arr<arr<unsigned char>*>();
    auto lts = new arr<unsigned char>();

    int k = 7;
    arr<unsigned char>* cd = 0;
    for (unsigned i = 0, j = 0, l = 0; i < dt.sz; i++) {
        if (j < 3 and k < 0) {
            k = 7;
            if (!j)
                printf("Ch%c ", l),
                lts->dd(l),
                j = 1, l = 0;
            else
                printf("Dc%d ", l),
                j = 3;
        }
        if (j < 3) l |= dt[i] << k--;
        else {
            if (!cd) {
                cd = new arr<unsigned char>();
                printf("Bn");
            }
            if (cd->sz == l) {
                cds->dd(cd);
                j = 0, i--, l = 0, cd = 0;
                printf("\n");
            } else
                printf("%d", dt[i]), cd->dd(dt[i]);
        }
    }
    cds->dd(cd), cd = 0;
    printf("\n");

    for (int i = 0; i < lts->sz; i++) {
        printf("%c ", lts->ar[i]);
        for (int j = 0; j < cds->ar[i]->sz; j++)
            printf("%d", cds->ar[i]->ar[j]);
        printf("\n");
    }
    for (int i = 0; i < arc->sz; i++)
        printf("%d", arc->ar[i]);

    FILE* res = fopen("/home/admin/CLionProjects/structs/tsk6/c.txt", "w");
    shfn2(lts, cds, arc, res);
    fclose(res);
}

