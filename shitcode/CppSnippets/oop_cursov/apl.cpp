
/* application implementation */

#include <iostream>
#include <cstring>

#include "apl.hpp"
#include "inn.hpp"
#include "dtu.hpp"
#include "dtr.hpp"
#include "dtd.hpp"
#include "stp.hpp"
#include "ouu.hpp"

apl::apl() : cl(xyn, mmx, xx, yy, ww, fgg) {
#	define nw(xyn, mmx, xx, yy, ww, fgg)
	
    stp* s = new stp nw;

    dtd* d = new dtd nw;
    d->sbs("sg1", s);
    d->sbs("sg2", s);

    dtr* r = new dtr nw;
    r->sbs("sg1", s);
    r->sbs("sg2", d);

    dtu* u = new dtu nw;
    ths.sbs("str", u);
    u->sbs("sg1", s);
    u->sbs("sg2", r);

    inn nw.scn();
    fdu();

    while (!fg)	brc("str", "");

    ouu nw.prt();
#	undef nw
}

// finds the digit one and returns 1
// returns 0 otherwise
void apl::fdu() {
    int a = 0, i = 0;

    for (; mmx[i][0] == 0 and i < xyn; i++, a++);

    if (mmx[a][1] == 1) { // if the digit one is below
        for (; mmx[a][0] == 1 and a < xyn; a++)
            xx = a;
	} else                // if it's above
        xx = a;
	
    mmx[xx][yy] = 2;
}

// matrix initialization
int** apl::nt() {
    int** a = new int*[xyn];
    for (int i = 0; i < xyn; i++)
        a[i] = new int[xyn];
    return a;
}
