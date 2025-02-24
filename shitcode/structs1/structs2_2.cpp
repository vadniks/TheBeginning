
#include <cstdio>
#include <cstdlib>
#include <ctime>

void scn(int n, int* a) {
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void prt(int n, int* a) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void srnd(int n, int* a) {
    srand(time(nullptr));

    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000 - 0;
}

int srch(int n, int* a, int v) {
    for (int i = 0; i < n; i++) {
        if (a[i] == v) 
            return i;
    }
    return -1;
}

int nsrch(int n, int* a) {
    for (int i = 0; i < n; i++) {
        if (a[i] < 0)
            return i;
    }
    return -1;
}

int* asrch(int n, int* a, int v, int& l) {
    int* b = new int[n];
    l = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == v) {
            b[l] = i;
            l++;
        }
    }
    return b;
}

int* gnsrt(int n, int* a, int v, int ndx) {
    if (!(ndx >= 0 && ndx < n))
        return nullptr;

    int* b = new int[n+1];
    for (int i = 0; i <= n; i++) {
        if (i < ndx)
            b[i] = a[i];
        else if (i == ndx)
            b[i] = v;
        else
            b[i] = a[(i > 0) ? i-1 : i];
    }
    return b;
}

void nsrt(int n, int* a, int v, int ndx) { 
    if (!(ndx >= 0 && ndx < n))
        return;
    
    a[ndx] = v;
}

int* rmv(int n, int* a, int ndx) {
    if (!(ndx >= 0 && ndx < n))
        return nullptr;

    int* b = new int[n-1];
    for (int i = 0; i < n-1; i++) {
        if (i < ndx)
            b[i] = a[i];
        else
            b[i] = a[i+1];
    }
    return b;
}

int* armv(int n, int* a, int v, int& l) {
    int* b = nullptr;
    l = n;
    for (int i = 0; i < n; i++) {
        if (a[i] == v) {
            b = rmv(l, (b != nullptr) ? b : a, i-(n-l));
            l--;
        }
    }
    return b;
}

int* qarmv(int n, int* a, int v, int& l) {
    int* b = new int[n];
    l = n;
    for (int i = 0, j = 0; i < n; i++) {
        if (a[i] == v)
            l--;
        else {
            b[j] = a[i];
            j++;
        }
    }
    return b;
}

int l1() {
    int n = 0;
    scanf("%d", &n);

    if (n > 1000 || n < 1) {
        printf("Error\n");
        return 1;
    }

    int* a = new int[n];
    scn(n, a);
    prt(n, a);
    srnd(n, a);
    prt(n, a);
    
    return 0;


    // const int n = 6; //   x
    // int a[n] = { 0, 1, 2, 2, 4, 5 };

    //prt(n+1, nsrt(n, a, 6, 0));
    //prt(n-1, rmv(n, a, 5));
    /*int nn = 0;
    int* b = armv(n, a, 2, nn);
    prt(nn, b);*/
    // int nn = 0;
    // int* b = armv(n, a, 2, nn);
    // prt(nn, b);
}

///////////////////////////////////////

int* dcrt(int n) 
{ return (int*) malloc(n * sizeof(int)); }

int* dscn(int n) {
    int* a = dcrt(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    return a;
}

int* dgnsrt(int n, int* a, int v, int ndx) {
    if (!(ndx >= 0 && ndx < n))
        return nullptr;

    a = (int*) realloc(a, (n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        if (i >= ndx) {
            if (i == ndx)
                a[i] = v;
            else
                a[i] = a[(i > 0) ? i-1 : i];
        }
    }
    return a;
}

int* drmv(int n, int* a, int ndx) {
    if (!(ndx >= 0 && ndx < n))
        return nullptr;

    for (int i = ndx; i < n-1; i++)
        a[i] = a[i+1];
    return (int*) realloc(a, (n-1) * sizeof(int));
}

int* darmv(int n, int* a, int v, int& l) {
    int* b = nullptr;
    l = n;
    for (int i = 0, j = 0; i < n; i++) {
        j = i-(n-l);
        if (a[j] == v) {
            b = drmv(l, (b != nullptr) ? b : a, j);
            l--;
        }
    }
    printf(" %d\n", l);
    return b;
}

int* dqarmv(int n, int* a, int v, int& l) {
    l = n;
    for (int i = 0, j = 0; i < n; i++) {
        if (a[i] == v)
            l--;
        else {
            a[j] = a[i];
            j++;
        }
    }
    return (int*) realloc(a, l * sizeof(int));
}

void l2() {
    const int n = 6;
    int* a = nullptr; //dcrt(n);
    for (int i = 0; i < n; i++)
        a = dgnsrt(n, a, i, i);

    try {
        a[5] = 2;
    } catch(...) {
        printf(" derfgdt");
    }

    prt(n, a);
    
    // drmv(n, a, 0);
    // prt(n-1, a);

    // int l = 0;
    // dqarmv(n, a, 2, l);

    dgnsrt(n, a, 0, 3);

    prt(n+1, a);
}

int main() {
    //l1();
    l2();
    return 0;
}
