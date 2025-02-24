// variant 8

#include <cstdio>
#include <cstdlib>
#include <map>
#include "a.h" // remove this

namespace aaa {

const unsigned ln = 4; // field length

// point (some cursor pointing at the current position) of the field's angle
/*
 |
 +-+
3| |
 +-+-
  4

3 is north (n) and 4 is east (e)
so it would be pt(4, 3)
*/
struct pt {
    const int e, n;
    pt(int e, int n) : e(e), n(n) {}
};

// matrix of angled points
const pt mt[ln][ln] = {
    { pt(5, 0), pt(7, 0), pt(8, 0), pt(0, 0) },
    { pt(3, 5), pt(2, 6), pt(5, 7), pt(0, 6) },
    { pt(5, 2), pt(7, 4), pt(9, 5), pt(0, 4) },
    { pt(4, 3), pt(6, 2), pt(7, 5), pt(0, 2) }
};

const int lg = ln - 1; // max matrix index

const char ee = 'e'; // east direction
const char nn = 'n'; // north direction
const char nl = '_'; // current state

// tree node
struct nd {
    char wh; // where (north or east)
    unsigned x, y;
    nd** ns; // child nodes
    unsigned nl; // child nodes count
    nd* pr = 0; // parent of this node

    nd(char wh, unsigned y, unsigned x, nd* pr)
        : wh(wh), y(y), x(x), ns(0), nl(0), pr(pr)
    {}

    // add child
    nd* dd(nd* a) {
        ns = (nd**) realloc(ns, sizeof(nd*) * ++nl);
        ns[nl - 1] = a;
        return this;
    }

    // print tree, b - count of paths, a - recursion level
    void prt(unsigned& b, unsigned a = 0) const {
        if (wh != nl) {
            for (unsigned i = 0; i < a; i++)
                printf("  ");
            printf("%c\n", wh);

            if (!nl) b++;
        }
        for (unsigned i = 0; i < nl; i++)
            ns[i]->prt(b, wh != nl ? a + 1 : a);
    }

    // find node
    nd* fnd(unsigned _y, unsigned _x) {
        if (_y == y and/*&&*/ _x == x) return this;
        nd* b = 0;
        for (unsigned i = 0; i < nl; i++)
            b = ns[i]->fnd(_y, _x);
        return b;
    }

    // walk from current node to the root node
    // and sum each node's weight
    unsigned cnt() {
        unsigned a = 0;
        nd* b = this;

        int _x = lg, _y = 0;
        int vl = 0; // value (weight of node)

        while (b->pr) {
            if (b->wh == ee) _x--;
            else _y++;

            // this can be done in the prc() function
            vl = b->wh == ee ? mt[_y][_x].e : mt[_y][_x].n;
            printf("%c(%d %d)_%d     ", b->wh, _y, _x, vl);

            a += vl;
            b = b->pr;
        }
        return a;
    }

    // find the shortest path weight (a, b - temporary variable)
    void shp(unsigned& a, unsigned b = 0) {
        if (pr and !nl) {
            b = cnt();
            printf("\n");
            if (b < a)
                a = b;
        }
        for (unsigned i = 0; i < nl; i++)
            ns[i]->shp(a);
    }
};

using namespace std;

map<unsigned, unsigned> aa;

// stack can be used here to avoid using tree structure somehow
// process the field
// (n - root, c - steps count, d - new direction)
void prc(nd*& n, unsigned& c, unsigned& bb, char d, int y = lg, int x = 0, unsigned lv = 0) {
    if (d != nl) c++;
    printf("%d %d %c %u\n", y, x, d, c);
    if (d == nl) printf("\n");

    // create root if necessary
    if (!n) {
        if (d != nl) throw 1;
        n = new nd(d, y, x, 0);
    } else { // find parent for new path's new node and insert it
        nd *a = 0;
        if (d == ee)
            a = n->fnd(y, x - 1);
        else
            a = n->fnd(y + 1, x);

        if (!a) a = n;
        a->dd(new nd(d, y, x, a));
    }

    // if target reached
    if (y == 0 and x == lg) {
        printf("# %d\n\n", bb);
        aa[lv] = bb;
        bb = 0;
        return;
    }

    // walk on field and make paths

    if (aa.co)
    bb = aa[lv];

    if (x < lg) {
        // printf("# %d\n", mt[y][x].e);
        bb += mt[y][x].e;
        prc(n, c, bb, ee, y, x + 1, lv + 1);
    }

    if (y > 0) {
        // printf("# %d\n", mt[y][x].n);
        bb += mt[y][x].n;
        prc(n, c, bb, nn, y - 1, x, lv + 1);
    }
}

};

// launch and test
void lnch() {
    using namespace aaa;
    unsigned c = 0;
    nd* a = 0;
    unsigned bb = 0;
    prc(a, c, bb, nl);

    printf("#-----\n");

    unsigned d = 0;
    a->prt(d);
    printf("%u\n", d);

    d = 1 << 31;
    a->shp(d);
    printf("%u\n", d);
}
