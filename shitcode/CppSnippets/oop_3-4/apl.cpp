
#include <iostream>
#include <cstring>

#include "apl.hpp"
#include "aa.hpp"
#include "bb.hpp"

apl::apl() : cl(0, 1, "apl", 1) {}

_nd _nn cl* apl::frt(
	int _n, 
	_nn cl* hd, 
	_nn cs nm, 
	int rd
) {
#	define nw(_x) return new _x(hd, nm, rd)

#	define _cs(y, _x) \
		case y:		  \
			_x;		  \
			break;

	switch (_n) {
		_cs(1, throw 1)
		_cs(2, nw(aa))
		_cs(3, nw(bb))
		default: throw 2;
	}
	
#	undef nw
#	undef _cs
}

void apl::trc() {
	ss rt = new char[bf];
	cin >> rt;
	nm = rt;
}

void apl::rn() {
	trc();
	
	sch();
	cout << "Object tree";
	prt();
	
	cout << "\nSet connects";
	scc();
	
	cout << "\nEmit signals";
	scm();
}

void apl::sch() {
	ss hd = 0, sj = 0;
	int n = 0, r = 0;
	
	while(1) {
		hd = new char[bf],
		sj = new char[bf];

		cin >> hd;
		if (!strcmp(hd, "endtree")) break;
		cin >> sj >> n >> r;

		cl* hhd = wlk(hd);
		if (!hhd)
			throw "0x1";
		else
			hhd->dd(frt(n, hhd, sj, r));
	}
}

void apl::scc() {
	int a = 0;
	ss 
		b = 0,
		c = 0;
	
	cl 
		*d = 0,
		*e = 0;
		
	while (1) {
		cin >> a;
		if (!a) break;
		
		b = new char[bf];
		c = new char[bf];
		cin >> b >> c;
		
		cout 
			<< endl 
			<< a 
			<< ' ' 
			<< b 
			<< ' ' 
			<< c;
		
		d = wlk(b);
		e = wlk(c);
		
		if (!d or !e) throw 1;
		
		d->sbs(a, e);
	}
}

void apl::scm() {
	ss
		a = 0,
		b = 0;

	cl* c = 0;
	while (1) {
		a = new char[bf];
		cin >> a;
		
		if (!strcmp(a, "endsignals"))
			break;
			
		b = new char[bf];
		cin >> b;
		
		c = wlk(a);
		if (!c) throw 1;
		
#		define _useless(x) &cl::x
		c->brc(b, _useless(sg));
#		undef _useless
	}
}
