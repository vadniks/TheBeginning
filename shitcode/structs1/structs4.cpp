
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cstring>

#define _c(_x, rgs...) \
    ([rgs]() -> bool { cm++; return _x; })()

#define _m mv++;

using namespace std;
 
int n;
int* a;

long cm = 0;
long mv = 0;

void b() {
	int i, j, c;
	bool k = 0;

	for (i = n; i > 1; i--) {
		k = 0;
	
    	for (j = 1; j < i; j++) {
			if (_c(a[j] < a[j-1], j)) {
                _m

				c = a[j];
				a[j] = a[j-1];
				a[j-1] = c;

				k = 1;
			}
		}
	
    	if (!k) break;
	}
}
 
void c() {
	for (int i = 0; i < n; i++)
		printf("%d\n", a[i]);
}

void r() {
    srand(time(0));
    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000 + 0;
}

void d() {
	int l = 0;
    int r = n-1;
    int ls = 0;
    int k = 0;

    while (l < r) {
        k = 0;

        for (int i = r; i > l; i--) {
            if (_c(a[i-1] > a[i], i)) {
                _m

                int c = a[i];
				a[i] = a[i-1];
				a[i-1] = c;

                ls = i;
                k = 1;
            }
        }
        l = ls;

        for (int i = l; i < r; i++) {
            if (_c(a[i] > a[i+1], i)) {
                _m

                int c = a[i];
				a[i] = a[i+1];
				a[i+1] = c;

                ls = i;
                k = 1;
            }
        }
        r = ls;

        if (!k) break;
    }
}

int* e(int* u, int* d, int l, int r) {
    if (l == r) {
        d[l] = u[l];
        return d;
    }

    int m = (l + r) / 2;

    int* ll = e(u, d, l, m);
    int* rr = e(u, d, m + 1, r);

    int* t = (ll == u) ? d : u;
    int ls = l, rs = m + 1;

    for (int i = l; i <= r; i++) {
        if (ls <= m && rs <= r){
            if (
                _c(
                    ll[ls] < rr[rs], 
                ll, ls, rr, rs)
            ) {
                
                _m
                
                t[i] = ll[ls];
                ls++;
            } else {
                _m

                t[i] = rr[rs];
                rs++;
            }
        } else if (ls <= m) {
            _m

            t[i] = ll[ls];
            ls++;
        } else {
            _m

            t[i] = rr[rs];
            rs++;
        }
    }
    return t;
}

template<typename t>
void drt(t act) {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;    
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    act();
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> b = t2 - t1;
    printf("\n%g\n\n",  b.count());
}

//#define __dbg

int main() {
    n = 100000;
    a = new int[n];
    bool bl = 0;

	r();

#ifdef __dbg
    c();
#endif

#if 0
    drt((bl) ? &b : &d);
#else
    int* t = new int[n];
    drt([t]() -> void { e(a, t, 0, n-1); });
#endif

#ifdef __dbg
    c();
#endif

    printf("\n%d %ld %ld\n", n, cm, mv);
	return 0;
}
