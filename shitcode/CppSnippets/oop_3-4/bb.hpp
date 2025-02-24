#ifndef __bb
#define __bb

#include "cl.hpp"

class bb final : public cl {
public:

	bb(cl* _nl hd, _nn cs nm, int rd) :
		cl(hd, 3, nm, rd)
	{}
	
	void sg(ss& a) override;
	void hnd(_nn ss a) override;
};

#endif
