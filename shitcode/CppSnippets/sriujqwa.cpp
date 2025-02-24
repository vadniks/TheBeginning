
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

#define ct(_x, y) cout << _x << ((y) ? '\n' : '\0');
#define acc(_x) [](int a, int b) -> int { return a _x b; }

typedef const int ci;
typedef int (*act)(int, int);

struct ox {
    char sg;
    act ac;

    ox(const char sg, act ac) {
        this->sg = sg;
        this->ac = ac;
    }

    ~ox() = default;
};

class A {

private:

    static ci lo = 4;

    const ox o[lo] = { 
        ox('+', acc(+)), 
        ox('-', acc(-)), 
        ox('*', acc(*)), 
        ox('%', acc(%)) 
    };

    const char _n = '\n';
    const char _s = ' ';

    static ci lns = 4;
    int ns[lns];

    static ci lsgs = 3;
    char sgs[lsgs];

    static ci ll = 1024;
    char ss[ll];

    static ci l = ll / lsgs;
    char s[l];

    int lst = 0;

    static ci lsp = 7;
    char** sp = new char*[lsp];

    static ci uf = -1;
    int nns[lsgs] = { uf, uf, uf };

    int r = uf;
	
public:
	
    A() { 
        ct(123 % -10 * 10 + -10, 1)
        ct(10 * 123 % -10 + -10, 1)
        ct(-10 + 123 % -10 * 10, 1)
        ct(-10 + 10 * 123 % -10, 1)
        ct(-1 * 2 * 3 + 2, 1)
        scan();
        split();
        parse();
        parseTimes();
        compile();
        ct(r, 0)
    }

	~A() = default;

private:

    void scan() {
        for (int i = 0; i < lsgs; i++) {
            cin.getline(s, l);
            int lg = strlen(s);
            
            if (i < lsgs-1) {
                s[lg] = _s;
                lg++;
            }

            for (int j = lst, k = 0; k < lg; j++, k++)
                ss[j] = s[k];
            
            lst += lg;
        }
    }

    void split() {
        vector<char> sl;
        for (int i = 0, j = 0; i <= lst; i++) {
            if (i < lst)
                sl.push_back(ss[i]);

            if (ss[i] == _s || i == lst) {
                sp[j] = new char[sl.size()];

                memcpy(sp[j], sl.data(), sl.size()*sizeof(char));   

                sl.clear();
                j++;
            }
        }
    }

    void parse() {
        for (int i = 0, j = 0, k = 0; i < lsp; i++) {
            char* ssp = sp[i];  

            if (i % 2 == 0) {
                ns[j] = atoi(ssp);
                j++;
            } else {
                sgs[k] = ssp[0];
                k++;
            }
        }
    }
    
    void parseTimes() {
        for (int i = 0; i < lsgs; i++) {
            char sg = sgs[i];
            char sgt = o[2].sg;
            char sgr = o[3].sg;
            
            if (sg == sgr) {
                if (i-1 >= 0 && (sgs[i-1] == sgt || sgs[i-1] == sgr)) {
                    int v = o[3].ac(nns[i-1], ns[i+1]);
                    nns[i] = v;
                    nns[i-1] = v;
                } else
                    nns[i] = o[3].ac(ns[i], ns[i+1]);
            } else if (sg == sgt) {
                if (i-1 >= 0 && (sgs[i-1] == sgr || sgs[i-1] == sgt)) {
                    int v = o[2].ac(nns[i-1], ns[i+1]);
                    nns[i] = v;
                    nns[i-1] = v;
                } else
                    nns[i] = o[2].ac(ns[i], ns[i+1]);
            }
        }

        for (int i = 0; i < lsgs; i++)
            ct(nns[i], 1)
    }

    void compile() {
        bool b = false;
        for (int i = 0; i < lsgs; i++) {
            char sg = sgs[i];

            for (int j = 0; j < lns-2; j++) {
                ox oo = o[j];

                if (sg == oo.sg) {
                    b = true;

                    int lv = (i == 0) ? ns[i] : (r == uf) ? nns[i-1] : r;
                    int rv = 0;
                    
                    if (i == 1)
                        lv = (nns[i-1] != uf) ? nns[i-1] : lv;  
                    
                    ci ndx = i + 1;
                    rv = (nns[ndx] != uf && i < lsgs-1) ? nns[ndx] : ns[ndx];

                    r = oo.ac(lv, rv);
                    break;
                }
            }
        }

        if (!b)
            r = nns[2];
    }
};

int main() {
	A();
	return 0;
}
