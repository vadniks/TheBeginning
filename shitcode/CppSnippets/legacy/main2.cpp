
#include <iostream>
#include <cstring>
#include <cstdlib>

#define ct(_x, y) cout << _x; if (y) cout << endl;

#define sc static const

#define _acc(_x) \
    [](int a, int b) -> int { return a _x b; }

using namespace std;

typedef int (*act)(int, int);

struct op {
    char s;
    act a;

    op(char s, act a) {
        this->s = s;
        this->a = a;
    }
    
    ~op() = default;
};

class A {

private:
    sc int bf = 256;
    sc char spc = ' ';
    sc int ltk = 7;
    sc int lns = 2;
    int r = 0;
    const char dl[1] = { spc };
    sc char q = 'C';

    sc int lo = 4;
    const op os[lo] = {
        op('+', _acc(+)),
        op('-', _acc(-)),
        op('*', _acc(*)),
        op('%', _acc(%))
    };

public:

    A() {
        for (int i = 0;; i++) {
            char st[bf] = { 0 };
            cin.getline(st, bf);

            if (st[0] == q)
                return;

            bool a = i == 0;
            //ct('|' << i, 1)

            int l = strlen(st);
            char sst[l+1];
            strncpy(sst, st, l);
            sst[l] = '\0';

            //ct('/' << sst << '|' << l << ' ' << strlen(sst) << ' ' << r, 1)

            int ns[lns] = { 0 };
            char sg;

            char* stt = nullptr;
            int tk = 0, j = 0;
            do {
                stt = strtok((tk == 0) ? sst : nullptr, dl);
                
                if (stt == nullptr)
                    break;
                
                //ct(' ' << stt << ' ' << i, 1)
                
                bool b = tk % 2 == 0; 
                
                //ct(' ' << stt << ' ' << a << ' ' << b << ' ' << (!a == !b), 1)
                
                //(a) ? b : !b
                if (!a == !b) {
                    ns[j] = atoi(stt);
                    j++;
                } else
                    sg = stt[0];

                tk++;
            } while (stt != nullptr);

            //ct('|' << sg, 1)

            int ns0 = ns[0];
            int ns1 = ns[1];
            for (int j = 0; j < lo; j++) {
                op o = os[j];
                
                if (sg == o.s)
                    (a) ? r += o.a(ns0, ns1) : r = o.a(r, ns0);
            }
            
            if ((i+1) % 3 == 0 && i > 3)
				printf("\n");

            if ((i+1) % 3 == 0 && !a)
                ct(r, 0);
        }
    }

    ~A() = default;
};

int main2() {
    A();
    return 0;
}
