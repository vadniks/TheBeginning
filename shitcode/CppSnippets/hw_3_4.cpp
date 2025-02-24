 
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

const char* FILE_NAME = "file.txt";
const int DEF_SIZE = 256;

void t1h3();
void t2h3();
void t3h3();
void t4h3();
void t5h3();

void t1h4();
void t2h4();
void t3h4();
void t4h4();
void t5h4();
void t6h4();
void t7h4();
void t8h4();
void t9h4();

int main() {
    t8h4();
    //cin.get();
    return 0;
}

void t1h3() {
    double m, s, r, n, p;

    cout << "enter s: ";
    cin >> s;

    cout << "enter p: ";
    cin >> p;

    cout << "enter n: ";
    cin >> n;

    r = p / 100;
    m = (s * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));

    cout << m;
}

void t2h3() {
    double  S, m, n, p, x, y;

    cout << "enter S" << endl;
    cin >> S;

    cout << "enter m" << endl;
    cin >> m;

    cout << "enter n" << endl;
    cin >> n;

    p = 1;
    do {
        p += 0.1;
        x = (1 + (p / 100));
        y = (S * (p / 100) * pow(x, n)) / (12 * (pow(x, n) - 1)) - m;
    } while (y < 0);

    cout << p;
}

void t3h3() {
    FILE* file;
    file = fopen(FILE_NAME, "r");

    if (file == nullptr) {
        cout << "there's no such file, creating then...\n";

        const char* c = "efqwf324g23vefqeqw3fqa3w";

        file = fopen(FILE_NAME, "w");
        fputs(c, file);
        fflush(file);
        fclose(file);

        cout << (file == nullptr) << ' ' << "file created, repeating...\n";
        file = fopen(FILE_NAME, "r");
    }

    cout << "reading file...\n";

    char* cnt = new char[DEF_SIZE];
    int i = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (i >= DEF_SIZE)
            break;

        i++;
        cnt[i] = (char) c;
    }
    fclose(file);

    cout << cnt;
}

void t4h3() {
    FILE* file;
    file = fopen(FILE_NAME, "r");

    if (file == nullptr) {
        cout << "error while opening file";
        return;
    }

    char c;
    while ((c = (char) fgetc(file)) != EOF) {
        for (char i = '0'; i <= '9'; i += (int) 1) {
            if (c == i)
                cout << c;
        }
    }
    fclose(file);
}

void t5h3() {
    const char* s = /*const_cast<char *>(*/"ejrsnvjsnnvueounsnweufinwejbglfhewfbhjdhdewvbhlvhvkewfjwkebkb"/*)*/;
    const int l = strlen(s);
    char* str = new char[l];

    for (int i = 0; i < l; i++)
        str[i] = s[i];

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {

            if (str[j] > str[i]) {
                char t = str[j];
                str[j] = str[i];
                str[i] = t;
            }
        }
    }

    cout << str;
}

/* ----------- */

void t1h4() {
    remove(FILE_NAME);

    FILE* file;
    file = fopen(FILE_NAME, "w");

    fputs("1234567891", file);
    fflush(file);
    fclose(file);

    file = fopen(FILE_NAME, "r");
    if (file == nullptr) {
        cout << "error while opening file";
        return;
    }

    int s = 0;
    int c = 0;
    while ((c = fgetc(file)) != EOF)
        s += c - '0';

    cout << s;
}

void t2h4() {
    int n;
    cout << "enter number:\n";
    cin >> n;

    if (n > 0)
        cout << "positive";
    else if (n == 0)
        cout << "zero";
    else if (n < 0)
        cout << "negative";
}

void t3h4() {
    double x = 10;
    double y = 10;
    double r = x / 2;

    auto areaR = [](double x, double y) -> double { return x * y; };

    auto areaT = [](double x, double y) -> double { return (x * y) / 2; };

    auto areaS = [](double r) -> double { return M_PI * r * r; };

    cout << areaR(x, y) << ' ' << areaT(x, y) << ' ' << areaS(r);
}

void t4h4() {
    const char s = '~'; /* star */
    const char lr = '#'; /* line red */
    const char lw = '-'; /* line white */

    const int xb = 8;
    const int yb = 6;
    const int xl = 45;
    const int yl = 7;
    //const int x = xb + xl;
    const int y = yb + yl;

    int sc = 0;
    int lc = 0;

    putc('\n', stdout);

    for (int j = 0; j < y; j++) {
        if (j < yb) {
            for (int ib = 0; ib < xb; ib++) {
                putc(s, stdout);
                sc++;
            }
        } else {
            for (int ib = 0; ib < xb; ib++) {
                if (j % 2 == 0)
                    putc(lr, stdout);
                else
                    putc(lw, stdout);
            }
        }
        for (int il = 0; il < xl; il++) {
            if (j % 2 == 0)
                putc(lr, stdout);
            else
                putc(lw, stdout);
        }
        putc('\n', stdout);
        lc++;
    }

    cout << '\n' << s << " - star, " << lr << " - line red, " << lw << " - line white\n";
    cout << "stars: " << sc << " lines: " << lc;
}

void t5h4() {
    const char dot = '*';
    const char none = ' ';

    const int xb = 0;
    const int xe = 360; // angle
    const int yb = 0;
//    int yb = -1; // sin
//    int ye = 1;

    int ym = 21; // -1, -0.9 -0.8 -0.7 -0.6 -0.5, -0.4 -0.4 -0.2 -0.1 0, ... 0.5, ... 1
    char canvas[xe][ym];

    auto sinf = [](int x) -> float { return /* y */ (float) (10 + 4 * sin(M_PI * x / 10)); };

    auto _round = [](float y) -> int {
        float a = round(y);
        //cout << a << "--\n";
        return (int) a;
    };

    float ys[xe];
    for (int i = xb; i <= xe; i++) {
        for (int j = yb; j <= ym; j++)
            canvas[i][j] = none;
        ys[i] = sinf(i);
    }

    for (int i = xb; i <= xe; i++)
        canvas[i][_round(ys[i])] = dot;

    for (int j = yb; j <= ym; j++) {
        for (int i = xb; i <= xe; i++)
            cout << canvas[i][j];
        cout << endl;
    }
}

void t6h4() {
    struct c_i {
        char ch;
        int d;

        c_i(char ch, int d) {
            this->ch = ch;
            this->d = d;
        }

        ~c_i() = default;
    };

    c_i cis[] = {
            c_i('i', 1),
            c_i('v', 5),
            c_i('x', 10),
            c_i('l', 50),
            c_i('c', 100),
            c_i('d', 500),
            c_i('m', 1000)
    };

    char str[DEF_SIZE];
    cout << "enter str:\n";
    cin >> str;

    int r = 0;

    for (char t : str) {
        for (c_i ci : cis) {
            if (t == ci.ch)
                r += ci.d;
        }
    }

    cout << r;
}

void t7h4() {
    int m = 37;
    int i = 3;
    int c = 64;
    int s = 0;

    cout << "enter prev s:\n";
    cin >> s;

    cout << (m * s + i) % c;
}

void t8h4() {
    const int ay = 3;
    const int ax = 4;
    const int by = 4;
    const int bx = 2;
    const int cy = 3;
    const int cx = 2;
    const int inner = 4;

    float a[ay][ax] = {
            { 5, 2, 0, 10 },
            { 3, 5, 2, 5 },
            { 20, 0, 0, 0 }
    };
    float b[by][bx] = {
            { 1.2, 0.5 },
            { 2.8, 0.4 },
            { 5.0, 1.0 },
            { 2.0, 1.5 }
    };

    // 3x4 4x2 4=4 -> 3x2

    float c[cy][cx] = { 0.0 };

    for (int j = 0; j < cy; j++) {
        for (int i = 0; i < cx; i++) {
            for (int k = 0; k < inner; k++)
                c[j][i] += a[j][k] * b[k][i];
            cout << c[j][i] << ' ';
        }
        cout << '\n';
    }
}

void t9h4() {
    const int pos1 = 16;
    const int pos2 = 8;

    struct c_i {
        char c;
        int d = 0;

        c_i(char c, int d) : c(c), d(d) {}

    };

    c_i* cis = (c_i*) malloc(sizeof(c_i) * pos1);
    cis[0] = c_i('a', 10);
    cis[1] = c_i('b', 11);
    cis[2] = c_i('c', 12);
    cis[3] = c_i('d', 13);
    cis[4] = c_i('e', 14);
    cis[5] = c_i('f', 15);

    for (int i = 6; i < pos1; i++)
        cis[i] = c_i((char) ('0' + (i - 6)), i - 6);

    int r = 0;

    char str[DEF_SIZE];
    cout << "enter str:\n";
    cin >> str;

    int size = 0;
    for (char i : str) {
        if (i == '\0')
            break;
        size++;
    }

    for (int i = size-1; i >= 0; i--) {
        char t = str[i];

        //cout << t << ' ' << i << "-\n";

        for (int j = 0; j < pos1; j++) {
            c_i ci = cis[j];

            if (t == ci.c) {
                int a = (int) pow(pos1, (size - 1) - (i));
                r += ci.d * a;

                //cout << a << ' ' << r << ' ' << ci.d << '\n';
            }
        }
    }

    cout << "dec: " << r << '\n';

    int ds[DEF_SIZE] = { 0 };
    int size2 = 0;
    for (int i = 0; r != 0; i++) {
        //cout << r << ' ';
        ds[i] = r % pos2;
        r = r / pos2;
        size2 = i + 1;
        //cout << i << ' ' << r << ' ' << ds[i] << "---\n";
    }

    int ds2[size2];
    for (int i = 0; i < size2; i++) {
        int a = ds[(size2 - 1) - i];
        ds2[i] = a;
        //cout << i << ' ' << a << ' ' << size2 << ' ' << ((size2 - 1) - i) << "----\n";
    }

    int r2 = 0;
    for (int i = 0; i < size2; i++)
        r2 = r2 * 10 + ds2[i];

    cout << "oct: " << r2;
}
