
/* implementation of the base class */

#include <iostream>
#include <cstring>
#include <cstdlib>

#include "cl.hpp"

cl::cl(ci& xy, int** mx, int& x, int& y, cs& w, int& fg) : 
    xy(xy),
    mx(mx),
    x(x),
    y(y),
    w(w),
    fg(fg),
    bss(vector<psc*>()) // create subscribers list
{}

// memory deallocation
cl::~cl() {
    //cls.clear();
    bss.clear();
    //delete nm;
}
/*
// add a child
void cl::dd(cl* a)
{ cls.push_back(a); }

// tree hierarchy output (print)
void cl::prt(int l) {
    cl** cls = gcls(); // childs
    int sz = gsz(); // their count
	
    cout << endl;
    for (int i = 0;
         i < l; 
         cout << "    ", i++);
    cout << ths.nm; // name
	
    for (int i = 0; i < sz; i++)
        cls[i]->prt(l + 1); // recursion
}

// unique name search (walk)
cl* cl::wlk(ss a) {
    if (!strcmp(ths.nm, a)) // names comparing
    return this;
	
    cl** cls = ths.gcls(); // childs
    int sz = ths.gsz(); // their count
	
    cl* r = 0; // result
    for (int i = 0; !r and i < sz; i++)
        r = cls[i]->wlk(a); // recursion
	
    return r;
}
*/
// subscribe
void cl::sbs(cs a, cl* b)
{ bss.push_back(new pr(a, b)); } // delegate to the vector

// broadcast
void cl::brc(cs a, cs b) {
    for (int i = 0; i < bss.size(); i++) {
        psc* c = bss[i];

        if (!strcmp(c->a, a))
            c->b->hnd(b);
    }
}

// unsubscribe
void cl::usb(int a)
{ bss.erase(bss.begin() + a); } // delegate to the vector
