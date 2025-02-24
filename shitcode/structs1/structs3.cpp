
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <chrono>

#define _l(_act, rgs...) \
    [rgs]() -> bool {    \
        cm++;            \
        return _act;     \
    }()

long cm = 0;
long mv = 0;

void srt(int n, int* a) {
    for (int i = 1; i < n; i++) {
        int j = i - 1, k = a[i];

        while (_l(j >= 0 and a[j] > k, a, j, k)) {
            mv++;
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = k;
    }
}

void rnd(int n, int* a) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000 + 0;
}

void adsc(int n, int* a, bool b) {
    for (int i = 0, j = n-1; i < n; i++, j--)
        a[i] = (b) ? i : j;
}

void prt(int n, int* a) {
    for (
        int i = 0; 
        i < n; 
        printf("%d\n", a[i]),
        i++);
}

void scn(int n, int* a) {
    for (
        int i = 0;
        i < n;
        scanf("%d\n", &a[i]),
        i++);
}

void drt(int n, int* a, void (*act)(int, int*)) {
    using namespace std;

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;	
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    act(n, a);
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> b = t2 - t1;
    printf("\n%g\n\n",  b.count());
}

void srt2(int n, int* a) {
    for (int i = 0; i < n; i++) {
        int j = i;
        
        for (int k = i+1; k < n; k++) {
            if (_l(a[k] < a[j], a, j, k))
                j = k;
        }

        mv++;
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}

int main() {
    const int n = 10000;
    int a[n] = { 0 /*4, 5, 8, 1, 2, 5, 0, 9, 7, 3*/ };

    //rnd(n, a);
    adsc(n, a, 1);
    //prt(n, a);
    printf("-\n");
    drt(n, a, (0) ? &srt : &srt2);
    //prt(n, a);
    printf("\n%ld %ld\n", cm, mv);

    return 0;
}
