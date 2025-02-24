
#pragma ide diagnostic ignored "modernize-use-nullptr"
#pragma ide diagnostic ignored "readability-make-member-function-const"
#pragma ide diagnostic ignored "cert-err34-c"

// variant 30

#include <cstdio>
#include <cstdlib>
#include "../a.h"

#define lmb(a, b...) [](b) { a; }

template<typename T>
class arr {
    typedef arr<T>* art;
public:
    const int sot;
    T* ar = 0;
    int sz = 0;

    [[gnu::used]]
    explicit arr(int sot) : sot(sot) {}
    ~arr() { delete[] ar; }

     art dd(T a) {
        ar = (T*) realloc(ar, sot * ++sz);
        ar[sz - 1] = a;
        return this;
    }

    template<typename... E>
    art dd(E ...a) {
        T b[] = {a...};
        for (T c : b)
            dd(c);
        return this;
    }

    template<typename... E>
    static art nw(int b, E ...a)
    { return (new arr<T>(b))->dd(a...); }

    [[gnu::unused]]
    art cp(T(*c)(T)) {
        auto a = new arr<T>(sizeof(T));
        for (int i = 0; i < sz; i++)
            a->dd(c ? c(ar[i]) : ar[i]);
        return a;
    }

    [[gnu::unused]]
    arr<T>& operator=(arr<T> a) {
        delete[] ar;
        ar = a.ar;
        sz = a.sz;
        return *this;
    }
};

typedef arr<int> iat;
typedef arr<iat*> art;

const int F = 100; //1 << 29;

class grph {
public:
    art* grp = new art(sizeof(iat*));

    template<typename... T>
    grph* dd(T... a) {
        grp->template dd(iat::nw(sizeof(int), a...));
        return this;
    }

    void itr(void(*a)(int), decltype(a) b, decltype(b) c) {
        int i = 0, j = 0;
        iat* k = 0;

        for (; i < grp->sz; i++) {
            k = grp->ar[i];

            if (c) c(i);
            for (; j < k->sz; j++)
                a(k->ar[j]);

            j = 0;
            if (b) b(i);
        }
    }

    void prt() {
        itr(lmb(a != F ? printf("%-2d ", a) : printf("%-2c ", '_'), int a),
            lmb(printf("\n"), int a), 0);
    }

    void fld() {
        int h = grp->sz, i = 0, j = 0, k = 0;
        auto g = [&](int b) { return grp->ar[b]->ar; };

        for (; i < h; i++)
            for (j = 0; j < h; j++)
                if (!g(i)[j] and i != j)
                    g(i)[j] = F;

        for (; k < h; k++)
            for (i = 0; i < h; i++)
                for (j = 0; j < h; j++)
                    if (g(i)[k] + g(k)[j] < g(i)[j])
                        g(i)[j] = g(i)[k] + g(k)[j];
    }
};

void lnch() {
    grph a;
//    a.dd(0, 4, 0, 2, 2, 0, 0, 0, 0);
//    a.dd(0, 0, 7, 0, 0, 3, 0, 0, 0);
//    a.dd(0, 0, 0, 0, 0, 2, 0, 0, 0);
//    a.dd(0, 0, 0, 0, 0, 0, 1, 1, 0);
//    a.dd(0, 2, 0, 3, 0, 2, 0, 6, 1);
//    a.dd(0, 0, 0, 0, 0, 0, 0, 0, 2);
//    a.dd(0, 0, 0, 0, 0, 0, 0, 5, 0);
//    a.dd(0, 0, 0, 0, 0, 0, 0, 0, 5);
//    a.dd(0, 0, 0, 0, 0, 0, 0, 0, 0);

//    a.dd(0, 1, 6, 0);
//    a.dd(0, 0, 4, 1);
//    a.dd(0, 0, 0, 0);
//    a.dd(0, 0, 1, 0);

//    a.dd(0, 5, 0, 10);
//    a.dd(0, 0, 3, 0);
//    a.dd(0, 0, 0, 1);
//    a.dd(0, 0, 0, 0);

    //   1  2  3  4  5  6  7  8  9  10
    a.dd(0, 3, 4, 2, 0, 0, 0, 0, 0, 0); //  1
    a.dd(0, 0, 0, 0, 0, 3, 0, 0, 0, 0); //  2
    a.dd(0, 0, 0, 0, 0, 3, 0, 0, 0, 0); //  3
    a.dd(0, 0, 0, 0, 5, 2, 0, 0, 0, 0); //  4
    a.dd(0, 0, 0, 0, 0, 0, 6, 0, 12, 0); // 5
    a.dd(0, 0, 0, 0, 0, 0, 8, 7, 0, 0); //  6
    a.dd(0, 0, 0, 0, 0, 0, 0, 0, 0, 4); //  7
    a.dd(0, 0, 0, 0, 0, 0, 0, 0, 0, 3); //  8
    a.dd(0, 0, 0, 0, 0, 0, 0, 6, 0, 11); // 9
    a.dd(0, 0, 0, 0, 0, 0, 0, 0, 0, 0); //  10

    a.prt();
    printf("\n");
    a.fld();
    a.prt();

    delete a.grp;
    a.grp = new art(sizeof(iat*));

    printf("\nEnter matrix size: ");
    int b = 0, c = 0;
    scanf("%d", &b);
    auto d = new iat(sizeof(int));

    printf("next line:\n");
    for (int i = 0, j; i < b; i++) {
        for (j = 0; j < b; j++) {
            printf("next: ");
            scanf(" %d", &c);
            if (c > F or c < 0)
                printf("error\n"), j--;
            else
                d->dd(c);
        }
        a.grp->dd(d);
        d = new iat(sizeof(int));
        printf("\nnext line:\n");
    }
    a.prt();
    a.fld();
    printf("\n");
    a.prt();
}

