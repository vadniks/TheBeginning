#ifndef __pr
#define __pr

template<
	typename l, 
	typename r>
struct pr {
	l a = 0;
	r b = 0;

	pr(l a, r b) : a(a), b(b) {}
	~pr() = default;
};
	
#endif
