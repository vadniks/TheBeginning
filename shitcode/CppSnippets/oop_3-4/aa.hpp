#ifndef __aa
#define __aa

#include "cl.hpp"

class aa final : public cl {
public:

	aa(cl* _nl hd, _nn cs nm, int rd) :
		cl(hd, 2, nm, rd)
	{}
	
	void sg(ss& a) override;
	void hnd(_nn ss a) override;
};

#endif
