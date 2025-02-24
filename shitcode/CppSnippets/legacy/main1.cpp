
#include <iostream>
#include <cstring>
#include <cstdlib>

#define ct(_x, y) cout << _x << ((y) ? '\n' : '\0');

#define _cs(y, _x) \
    case y:        \
        _x;        \
        break;

#define sc static const

using namespace std;

class A {

private:
    sc int lgt = 3;
    sc int bf = 256;
    sc char spc = ' ';
    sc int ltk = 7;
    sc int lns = 2;
    int r = 0;

public:

    A() {
        for (int i = 0; i < lgt; i++) {
            char st[bf] = { 0 };
            cin.getline(st, bf);

            int l = strlen(st);
            char sst[l+1];
            strncpy(sst, st, l);
            sst[l] = '\0';

            //ct('/' << sst << '|' << l << ' ' << strlen(sst) << ' ' << r, 1)

            int ns[lns] = { 0 };
            char sg;

            bool a = i == 0;

            char* stt = nullptr;
            int tk = 0, j = 0;
            do {
                stt = 
                    strtok((tk == 0) ? sst : nullptr,
                        (char[]) { spc });
                
                if (stt == nullptr)
                    break;
                
                bool b = tk % 2 == 0; //ct('\\' << stt << ' ' << b, 1)
                if ((a) ? b : !b) {
                    ns[j] = atoi(stt);
                    j++;
                } else
                    sg = stt[0];

                tk++;
            } while (stt != nullptr);

            //ct('|' << sg, 1)

            int ns0 = ns[0];
            int ns1 = ns[1];
            switch (sg) {
                _cs('+', (a) ? r += ns0 + ns1 : r += ns0)
                _cs('-', (a) ? r += ns0 - ns1 : r -= ns0)
                _cs('*', (a) ? r += ns0 * ns1 : r *= ns0)
                _cs('%', (a) ? r += ns0 % ns1 : r %= ns0)
            }
        }
        
        ct(r, 0)
    }

    ~A() = default;
};

int main1() {
    A();
    return 0;
}
