
// variant 17

#include <cstdio>
#include <cstdlib>
#include "../a.h"

template<typename T>
class arr {
    typedef arr<T> *art;
public:
    const int sot = sizeof(T);
    T *ar = 0;
    int sz = 0;

    ~arr() { delete[] ar; }

    art dd(T a) {
        ar = (T *) realloc(ar, sot * ++sz);
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
};

void pbn(int n, arr<char>& a) {
    if (n / 2)
        pbn(n / 2, a);
    a.dd((char) ('0' + n % 2));
}

arr<int>** lz77(const char* st, const int ln) {
    // Initialized variables
    const int asz = 3;

    auto res = new arr<int>*[asz];

    // Declare an arry to store every char info st string called 'chnf'
    int** chnf = new int*[asz];
    for (int i = 0; i < asz; i++) {
        chnf[i] = (int *) calloc(ln, sizeof(int));
        res[i] = new arr<int>();
    }

    res[0]->dd(0);
    res[1]->dd(0);
    res[2]->dd((unsigned char) st[0]);

    // A loop to perform some operations st every char st st string
    for (int i = 1; i < ln; i++) {

        // A loop to check st char st position i is equal to any of
        // previous char st st and save this info st chnf array
        for (int j = 0; j < i; j++) {

            // Check position of previous view of element i
            if (st[i] == st[j])
                // Set position pointer
                chnf[0][j] = i - j;
        }

        // A loop to check ln for every char position
        for (int j = 0; j < ln; j++) {
            // Set bg point
            int bg = i - chnf[0][j];
            // Set ct to calculate ln for this char position
            int ct = 1;

            // A loop to check ln for this char position
            for (int k = 0; k < ln; k++) {
                // Check nx element of bg by nx element of st

                if ((bg + ct < ln ? st[bg + ct] : -1) ==
                    (i + ct < ln ? st[i + ct] : -1))
                    ct++; // Increase ct by 1
                else {
                    chnf[1][j] = ct; // Store ct value st ln

                    // Check if this st char is the last char
                    if (i != (ln - 1)) {
                        // Store nx char to char info
                        // Check this postion is equal to ln
                        if (chnf[0][j] + ct == ln)
                            chnf[2][j] = 0; // Set 0 st nx char field
                        else
                            chnf[2][j] = (unsigned char)
                                    st[chnf[0][j] + ct]; // Set the nx char
                    } else
                        chnf[2][j] = 0; // Set NULL st nx char field
                    break; // Stop loop
                }
            }
        }

        // Set lr selector
        int lr = 0; // lr selector equal 0

        // Loop to check the largest ln for every char info
        for (int k = 1; k < ln; k++)
            // Check largest
            if (chnf[1][lr] <= chnf[1][k])
                lr = k; // Set largest

        // Check largest ln is equal to 0
        if (chnf[1][lr])
            i += chnf[1][lr]; // increase loop counter by ln of the largest char info element
        chnf[2][lr] = (unsigned char) st[i]; // Set char info

        printf("%d, %d, %c\n",
               chnf[0][lr], chnf[1][lr], (char) chnf[2][lr]);

        res[0]->dd(chnf[0][lr]);
        res[1]->dd(chnf[1][lr]);
        res[2]->dd(chnf[2][lr]);

        // Prepare char info array for nx char by set it to 0
        for (int z = 0; z < asz; z++)
            for (int j = 0; j < ln; j++)
                chnf[z][j] = 0; // Set every element st char info to 0
    }
    return res;
}

arr<char>* cpy(arr<char>* a) {
    auto b = new arr<char>();
    for (int i = 0; i < a->sz; i++)
        b->dd(a->ar[i]);
    return b;
}

bool eql(arr<char>* a, arr<char>* b) {
    if (a->sz != b->sz) return 0;
    for (int i = 0; i < a->sz; i++)
        if (a->ar[i] != b->ar[i])
            return 0;
    return 1;
}

struct nd {
    int dx;
    arr<char>* vl;
    nd* nx;

    nd(int dx, arr<char>* vl) : dx(dx), vl(vl), nx(0) {}
};

void ins(nd* hd, int dx, arr<char>* vl) {
    nd* a = new nd(dx, vl);
    nd* b = hd;

    while (b) {
        if (!b->nx) {
            b->nx = a;
            return;
        }
        b = b->nx;
    }
}

nd* srn(nd* hd, arr<char>* vl) {
    nd* a = hd;
    while (a)
        if (eql(vl, a->vl))
            return a;
        else
            a = a->nx;
    return 0;
}

/*
0,a
0,b
1,b
1,a
3,b
*/

void lz78(const char* st, const int ln) {
    int ls, dx = 1;

    arr<char> wrd;
    wrd.dd(st[0]);

    nd* dct;
    dct = new nd(1, cpy(&wrd));

    printf("0,%s\n", wrd.ar);

    for (int i = 1; i < ln; i++) {
        arr<char> ar;
        ar.dd(st[i]);

        for (nd* fn = srn(dct, &ar);
             fn;
             fn = srn(dct, &ar)
        ) {
            i++;
            ar.dd(i + 1 < ln ? st[i] : '\0');
            ls = fn->dx;
        }

        printf("%d,%c\n",
               ar.sz < 2 ? 0 : ls, i + 1 < ln ? st[i] : '\0');

        dx++;
        if (i != ln)
            ins(dct, dx, cpy(&ar));
    }
}

void lnch6() {
//    lz77("0000000111111111111000000000011011110", 38);

//    for (int i = 0; i < a[0]->sz; i++) {
//        auto b = arr<char>();
//        pbn(a[0]->ar[i], b);
//        b.dd('\0');
//        printf("%5s, ", b.ar);
//    }
//    printf("\n");
//
//    for (int i = 0; i < a[1]->sz; i++) {
//        auto b = arr<char>();
//        pbn(a[1]->ar[i], b);
//        b.dd('\0');
//        printf("%5s, ", b.ar);
//    }
//    printf("\n");
//
//    for (int i = 0; i < a[2]->sz; i++)
//        printf("%5c, ", (char) a[2]->ar[i]);
//    printf("\n");

//    lz77("00000001111111111110 00000000011011110", 38);
//    lz77("0001000010101001101", 19);

//    lz78("ababaaabb", 9);
//    lz78("ACAGAATAGAGA", 12);
//    lz78("webwerbweberweberweb", 20);
}
