// variant 8

#include <cstdio>
#include <cstdlib>
#include "../a.h"

namespace bbb {

    const int ln = 3; // field length

//    const int mt[ln][ln] {
//        { 2, 1, 3 },
//        { 4, 0, 1 },
//        { 1, 2, 7 }
//    };
//    const int mt[ln][ln] {
//        { 1, 2, 3 },
//        { 4, 5, 6 },
//        { 7, 8, 9 }
//    };
    const int mt[ln][ln] {
            { 9, 8, 7 },
            { 6, 5, 4 },
            { 3, 2, 1 }
    };

    const int lg = ln - 1; // max matrix index

    unsigned cmps = 0;
#   define __cmp cmps++;

// tree node
    struct nd {
        int x = 0, y = 0;
        nd** ns = 0; // child nodes
        int nl = 0; // child nodes count
        nd* pr = 0; // parent of this node
        int vl = 0;

        nd(int y, int x, nd* pr, int vl)
            : y(y), x(x), pr(pr), vl(vl)
        {}

        // add child
        void dd(nd* a) {
            ns = (nd**) realloc(ns, sizeof(nd*) * ++nl);
            ns[nl - 1] = a;
        }

        // walk from current node to the root node
        // and sum each node's weight
        int cnt() {
            int a = 0;
            nd* b = this;

            int _x = lg, _y = 0;
            while (b->pr) {
                printf("(%d %d)_%d     ", _y, _x, b->vl);

                __cmp

                a += b->vl;
                b = b->pr;
            }
            return a;
        }

        // find the shortest path weight (a, b - temporary variable)
        static void shp(nd** lfs, int lfn, int& a) {
            for (unsigned i = 0; i < lfn; i++) {
                auto b = lfs[i]->cnt();
                printf("\n");

                if (b < a)
                    a = b;
            }
        }
    };

// stack can be used here to avoid using tree structure somehow
// process the field
    void prc(nd* n, nd**& lfs, int& lfn, int y = lg, int x = 0) {
        printf("%d %d\n", y, x);

        int tm = mt[y][x];
        nd* t = new nd(y, x, n, tm);

        auto gt = [&]() { return n->ns[n->nl - 1]; };

        __cmp

        // if target reached
        if (y == 0 and x == lg) {
            n->dd(t);

            lfs = (nd**) realloc(lfs, sizeof(nd*) * ++lfn);
            lfs[lfn - 1] = gt();
            return;
        }

        if (x < lg or y > 0) n->dd(t);
        else delete t;

        // walk on field and make paths
        if (x < lg)
            prc(gt(), lfs, lfn, y, x + 1);

        if (y > 0)
            prc(gt(), lfs, lfn, y - 1, x);
    }
};

// launch and test
void lnch17() {
    using namespace bbb;
    nd* a = new nd(lg, 0, 0, 0);
    nd** lfs = 0;
    int lfn = 0;
    prc(a, lfs, lfn);

    printf("#-----\n");

    int d = 0;
    printf("%d\n", d);

    d = 1 << 15;
    nd::shp(lfs, lfn, d);
    printf("%d %u\n", d, cmps);
}
