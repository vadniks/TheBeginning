
// variant 3

#include <cstdio>
#include <cstdlib>

#define _nn [[gnu::nonnull]]
#define _nl _Nullable
#define _nd [[nodiscard]]

#define _r(_x) { return _x; }

#define rlc(x, y) \
    (char*) realloc(x, y * sizeof(char));

typedef char* ss;

////////////////////////////////////////

const char u = -1, v = '(', w = ')';
_nd bool ck(_nn ss a, int b = 0, int c = 0) {
    char d = a[b];
    
    if (d == v)
        c++;
    else if (d == w)
        c--;
    else if (d == '\0')
        return !c;

    return ck(a, b + 1, c);
}

////////////////////////////////////////

_nd bool a(_nn ss a) {
    const char 
        e = '{',
        f = '}';

    static ss d = 0;
    static int i = 0;

    void (*dd)(char a) = [](char a) {
        d = rlc(d, i + 1)
        d[i] = a;
        i++;
    };
    
    _nd char* _nl (*pl)(void) = 
        []() -> char* _nl {
            if (!d) return 0;

            char* a = &d[i];
            i--;
            d = rlc(d, i)
            
            return a;
        };

    for (
        int b = 0, c = 0; 
        (char) b != '\0'; 
        b = a[c], c++
    ) {
        if (!b) continue;

        if (b == e)
            dd(b);
        else {
            if (!pl())
                return 0;
        }
    }
    return 1;
}

////////////////////////////////////////

// 12345 / 10 = 1234
// 12345 % 10 = 5
_nd bool dv(int a, int e = 0, bool d = 1) {
    if (!a) return d;

    int b = a % 10;
    bool c = d and !(e % (!b ? 1 : b));

    return dv(a / 10, a, c);
}

////////////////////////////////////////

int main() {
    printf("%d\n", dv(321)); //248 111
    printf("%d\n", ck((ss) "(((()(())))())")); 
    //"(((())())(()()))")); 
    //"()((()((())(())()()(((()()"));
    return 0;
}
