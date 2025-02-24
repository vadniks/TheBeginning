

#include <iostream>
#include <vector>

using namespace std;

void spinner() {
    const int a = 20;
    const int b = 10;
    const int c = 55;
    int res = 0;

    float n = (float) (c - a) / b; // a + b * n <= c
    int n1 = (int) n; // if n = 3.5 n1 will be 3 (n1 will be less than n), if n = 3 then n1 = 3 too (n <= (...))
    res = n1;

    cout << "n = " << res;
}

void spinner2() {
    const int m = 10;
    const int xi = 3;
    const int yj = 4;
    int x = 0;
    int y = 0;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            if (m == (i * xi + j * yj)) {
                x = i;
                y = j;
            }
        }
    }

    cout << "m = " << x << " * 3 + " << y << " * 4";
}

class Balls {

private:
    static const int N = 10;
    int items[N];
    int res;
    int c = 0;

public:
    Balls() {
        res = 0;

        const int st = 0;
        const int bl = 5;
    	
    	for (int i = 1; i < N; i++)
    		res += fact(i);
    	
        cout << '\n' << res;
    }

	int fact(int a) {
		int f1 = 1;
		if (a == 1)
			return 1;
		else if (a > 1)
			return a * fact(a - 1);
		else
			return 0;
	}

public:
    ~Balls() = default;
};

void euclid() {
    const int n1 = 1180;
    const int n2 = 482;
    int res;

    int rem = n2;
    int prevRem = n1;
    while (rem != 0) {
        int remTemp = prevRem % rem;

        if (remTemp == 0)
            res = rem;

        cout << prevRem << " / " << rem << " ( " << remTemp << " )" << '\n';

        prevRem = rem;
        rem = remTemp;
    }

    cout << res;
}

#define I(x) items[x]

void sieve() {
    const int bord = 30;
    const int b = bord - 1;
    const int srkd = 0;
    int items[bord];

    for (int i = 0, j = 2; i < b; i++, j++) {
        I(i) = j;
        //cout << j << ' ';
    }
    //cout << '\n';

    for (int i = 0; i < bord; i++) {
        const int dr = I(i);

        for (int j = 0; j < bord; j++) {
            const int dd = I(j);

            if (dr == srkd || dd == srkd || dr == dd)
                continue;

            if (dr % dd == 0)
                I(i) = srkd;
        }
        //cout << I(i) << ' ';
    }

    //cout << '\n';

    cout << bord << " : ";
    for (int i = 0; i < bord; i++) {
        if (I(i) != 0)
            cout << items[i] << ' ';
    }
}

#undef I

/*
namespace files {
//    const FILE* file;
//    const char* fn = "file.txt";
//
//    void init() {
//        file = fopen(fn, );
//    }

    const char* str = "hio ebg wehn fof hno  iwe  hf38y9   q39 r8p";
    const int len = strlen(str);

    void t1() {
        const char c1 = ' ';
        const char c2 = '*';
        //char* s = new char[len];

        for (int i = 0; i < len; i++) {
            if (str[i] == c1)
                cout << c2;
            else
                cout << str[i];
        }
    }

    void t2() {
        const char* s = R"()";
    }
}

using namespace files;
*/

using namespace balls;

int main() {
    //spinner2();
    bStarter();
    //cout << ' ' << kol_perestanovok.size();
    //Balls();
    return 0;
}
