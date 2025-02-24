
#include <iostream>
#include <cstring>
#include <cstdlib>

#include "cl.hpp"

cl::cl(cl* _nl hd, int n, _nn cs nm, int rd) : 
	nm(nm),
	n(n),
	hd(hd),
	cls(vector<cl*>()),
	rd(rd),
	bss(vector<pip>())
{}

cl::~cl() {
	cls.clear();
	bss.clear();
	delete nm;
}

_nd _nn cl**     cl::gcls() _r(cls.data())
_nd     int      cl::gsz()  _r(cls.size())
_nd _nn cs       cl::gnm()  _r(nm)
_nd _nn act<cl>  cl::gsp() _r(&cl::sg)

void cl::dd(_nn cl* a)
{ cls.push_back(a); }

void cl::prt(int l) {
	cl** cls = gcls();
	int sz = gsz();
	
	cout << endl;
	for (
		int i = 0;
		i < l; 
		cout << "    ", i++);
	cout << ths.nm;
	
	for (int i = 0; i < sz; i++)
		cls[i]->prt(l + 1);
}

_nd cl* _nl cl::wlk(_nn ss a) {
	if (!strcmp(ths.nm, a))
		return this;
	
	cl** cls = ths.gcls();
	int sz = ths.gsz();
	
	cl* r = 0;
	for (int i = 0; !r and i < sz; i++)
		r = cls[i]->wlk(a);
	
	return r;
}

void cl::sbs(int a, _nn cl* b)
{ bss.push_back(new pic(a, b)); }

void cl::brc(_nn ss e, _nn act<cl> d) {
	(this->*d)(e);
	
	pip c = 0;
	for (
		int a = bss.size(), b = 0; 
		b < a; 
		b++
	) {
		c = bss[b];
		if (!c or !c->b) throw 1;
		
		cout
			<< "\nSignal to "
			<< c->b->nm
			<< " Text: " 
			<< ths.nm
			<< " -> ";

		if (c->b->gsp() == d)
			c->b->hnd(e);
	}
}

void cl::usb(int a)
{ bss.erase(bss.begin() + a); }

void cl::sg(ss& a) {}

void cl::hnd(_nn ss a) 
{ cout << a; }
