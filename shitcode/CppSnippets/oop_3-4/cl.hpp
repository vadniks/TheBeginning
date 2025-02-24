#ifndef __cl
#define __cl

#include <vector>

#include "dcls.hpp"
#include "pr.hpp"

#define pic pr<int, cl*>
#define pip pic*

class cl {
protected:
	cs          nm;
	cl*         hd;
	vector<cl*> cls;
	int         rd;
	const int   n;
	vector<pip> bss;

public:

	cl(cl* _nl hd, int n, _nn cs nm, int rd);
	~cl();

	_nd _nn cl**     gcls();
	_nd     int      gsz();
	_nd _nn cs       gnm();
	_nd _nn act<cl>  gsp();

		void    dd(_nn cl* a);
	_nd cl* _nl wlk(_nn ss a);
		void    prt(int l = 0);
	
	void sbs(int a, _nn cl* b);
	void brc(_nn ss a, _nn act<cl> b);
	
	__attribute__((deprecated, unused))
	void usb(int a);
	
	virtual void sg(ss& a);
	virtual void hnd(_nn ss a);
};

#endif
