#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define ct(x) cout << x << endl;

#define _f(_i, _j, _k, _l) \
        for (int _l = _i; _l _k _j; _l++)

#define l(x) ([i]() -> bool { c++; return x; })()

const int k = 2;
int n = 10;
int x[] = { 1, 2, 3, 2, 2, 2, 5, 2, 2, 2 };

int c = 0;
int d = 0;

void a1() {
    int i = 0;
    while (l(i <= n)) {
        if (x[i] == k) {
            _f(i, n-1, <=, j) {
                d++;
                x[j] = x[j+1];
            }
            n = n - 1;
        } else
            i = i + 1;
    }
}

void a2() {
    int j = 0;
    for (int i = 0; l(i < n); i++) {
        x[j] = x[i];
        d++;
        if (x[i] != k)
            j++;
    }
    n = j;
}

 void f() {
     srand(time(nullptr));

     _f(0, n, <, i)
        x[i] = rand() % 9 + 1;
 }

void p() {
    _f(0, n, <, i)
        ct(x[i])
}

int main() {
    a2();
    
    p();
    ct(c << ' ' << d)
}



void b(int n) {
    int c = 0;

    const int bb = 8;
    int b[bb] = { 0 };
    
    int t = 0;
    int tt = 0;

    bool d = true;

    while (c <= n) {
        t = c;
        while (t != 0) {
            b[tt] = t % 10;
            t /= 10;
            tt++;
        }
        t = 0;

        // for (int i = 0; i < tt; i++)
        //     cout << ' ' << b[i];
        // cout << endl;
        
        d = true;
        for (int i = 0; i < tt; i++) {
            if (b[i] != 0) {
                d &= c % b[i] == 0;
                //cout << "\n " << c << ' ' << b[i] << ((c % b[i] == 0) ? 't' : 'f');
            }
        }
        tt = 0;
        
        //cout << endl;
        
        if (d)
            ct(c)
        
        c++;
    }
}

void b(int n) {
    int c = 1;
    int a = 0;

    const int bb = 8;
    int b[bb] = { 0 };
    
    int t = 0;
    int tt = 0;

    bool d = true;

    while (c <= n) {
        for (t = c; t != 0 && tt < bb; tt++) {
            b[tt] = t % 10;
            t /= 10;
        }
        t = 0;
        
        d = true;
        for (int i = 0; i <= tt; i++) {
            if (b[i] != 0)
                d &= c % b[i] == 0;
        }
        tt = 0;
        
        if (d)
            a++;
        
        c++;
    }
    ct(a);
}



#include <iostream>

using namespace std;

#define ct(x) cout << x << endl;

int main() {
    int k = 2;
    int n = 10;
    int x[] = { 1, 2, 3, 2, 2, 2, 5, 2, 2, 2 };

#if (true)
    int j = 0;
    for (int i = 0; i < n; i++) {
        x[j] = x[i];
        if (x[i] != k)
            j++;
    }
    n = j;

    for (int j = 0; j < n; j++)
        ct(x[j])
#else
    int i = 1;
    while (i <= n) {
        if (x[i] == k) {
            for (int j = i; j <= n-1; j++)
                x[j] = x[j+1];
            n = n - 1;
        } else
            i = i + 1;
    }

    for (int j = 0; j < n; j++)
        ct(x[j])
#endif
}
