#ifndef __apl
#define __apl

#include "dcls.hpp"
#include "cl.hpp"

class apl final : cl {
public:

	apl();

	void trc();
	void rn();
	
	_nd ss sbs(_nn ss a, int n);
	
	_nd _nn cl* frt(
		int _n, 
		_nn cl* hd, 
		_nn cs nm, 
		int rd);
	
	void sch();
	void scc();
	void scm();
};

#endif
