

#include <iostream>
#include <vector>
#include <cstring>
#include <functional>
#include <cmath>

using namespace std;

typedef char* c_str;

void fileTreatment();
void file();
void row();
void pyth();

int main() {
    pyth();
    //row();
    //file();
    //fileTreatment();
    return 0;
}

void pyth() {
    int n = 1;
    int m = 15;

    for (int i = n; i <= m; i++) {
        for (int j = n; j <= m; j++) {
            for (int k = n; k <= m; k++) {
                int a = (i * i + j * j);
                if (a == k * k)
                    cout << i << ' ' << j << ' ' << k << " | ";
            }
        }
    }
}

void row() {
    const double e = /*0.00001;*/ (1 / pow(3, 10));
    double res = 0.0;

    int n = 1;
    double i = 0.0;

    /*do {
        i = 1 / pow(3, n);
        double frml = i * pow(cos(pow(3, n - 1)), 3);
        res += frml;
        cout << i << ' ' << n << ' ' << frml *//*<< ' ' << res*//* << '\n';
        n += 1;
    } while (i >= e);*/

    while ((i = (1 / pow(3, n))) >= e) {
        //cout << res << ' ';
        double frml = (i * pow(cos(pow(3, n - 1)), 3));
        res += frml;
        cout << i << ' ' << n << ' ' << frml << ' ' << res << '\n';
        n++;
    }

    cout << '\n' << res;
}

//struct arr {
//    int* ar;
//    int size;
//
//    arr(int *ar, int size) {
//        this->ar = ar;
//        this->size = size;
//    }
//
//    ~arr() = default;
//};

/*arr getInts(float a) {
    vector<int> r;

    float aa = a;
    while (aa != 0) {
        aa = aa * 10;
        r.push_back((int) (aa % 10.0f));
    }

    int* rr = new int[r.size()];
    rr = r.data();
    return arr(rr, r.size());
}*/

int sumInts(int a) {
    int r = 0;

    while (a != 0) {
        r += a % 10;
        a = a / 10;
    }

    return r;
}

c_str subStrAftDot(c_str s) {
    int len = strlen(s);

    int dotPos = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '.') {
            dotPos = i;
            break;
        }
    }

    char* r = new char[(len-1) - dotPos];
    for (int i = dotPos+1, j = 0; i < len; i++, j++)
        r[j] = s[i];

    cout << "\n-- " << s << ' ' << r << '\n';

    return r;
}

void file() {
    const char div = ' ';
    FILE* f = fopen("/home/admin/Desktop/file2.txt", "r");

    struct word {
        float num;
        int fract;

        word(float num, int fract) : num(num), fract(fract) {}

        ~word() = default;
    };

    vector<word> words;
    vector<char> chars(0);
    {
        int c;
        int i = 0;
        while ((c = fgetc(f)) != EOF) {
            cout << (char) c;
            chars.push_back((char) c);
            i++;
        }
        chars.resize(i-1);
        //cout << chars[i-2] << '\n';
        //if (chars[i] != div)
        chars.push_back(div);
    }

    cout << "|\n";

    const int size = chars.size();

    vector<char> tempStr(0);
    for (int i = 0; i < size; i++) {
        char c = chars[i];
        //cout << c;
        if (c != div) {
//            cout << c;
            tempStr.push_back(c);
        } else {
            int tl = tempStr.size();
            char* ts = new char[tl]();
            for (int j = 0; j < tl; j++)
                ts[j] = tempStr[j];
            ts[tl] = '\0';

            cout << ts << ' ' << tl << " -\n";

            words.push_back(word(stof(ts), stoi(subStrAftDot(ts))));

            vector<char>(0).swap(tempStr);
        }
    }

    cout << words.size() << '\n';

    for (int i = 0; i < words.size(); i++) {
        float s = words.at(i).num;
        cout << s << " --\n";
    }

    cout << '\n';

    int wSize = words.size();
    for (int i = 0; i < wSize; i++) {
        for (int j = 0; j < wSize; j++) {
            if (sumInts(words[i].fract) > sumInts(words[j].fract)) {
                word t = words[i];
                words[i] = words[j];
                words[j] = t;
            }
        }
    }

    for (int i = 0; i < words.size(); i++)
        cout << words[i].num << " ---\n";
}

int scmp(c_str s1, c_str s2, int i, int s1r, int s2r) {
    int res = 0;

    if (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] > s2[i])
            s1r += 1;
        else
            s2r += 1;

        scmp(s1, s2, i+1, s1r, s2r);
    } else {
        if (s1r > s2r)
            res = 1;
        else
            res = 2;
    }

    return res;
};

void fileTreatment() {
    const char div = ' ';
    FILE* f = fopen("/home/admin/Desktop/file.txt", "r");

    vector<c_str> words(0);
    vector<char> chars(0);
    {
        int c;
        int i = 0;
        while ((c = fgetc(f)) != EOF) {
            cout << (char) c;
            chars.push_back((char) c);
            i++;
        }
        chars.resize(i-2);
        //cout << chars[i-2] << '\n';
        //if (chars[i] != div)
            chars.push_back(div);
    }

    cout << "|\n";

    const int size = chars.size();

    vector<char> tempStr(0);
    for (int i = 0; i < size; i++) {
        char c = chars[i];
        //cout << c;
        if (c != div) {
//            cout << c;
            tempStr.push_back(c);
        } else {
            int tl = tempStr.size();
            char* ts = new char[tl];
            for (int j = 0; j < tl; j++)
                ts[j] = tempStr[j];

            words.push_back(ts);

            vector<char>(0).swap(tempStr);
//            tempStr.clear();
//            tempStr.shrink_to_fit();
            cout << ts << " -\n";
        }
    }

    cout << words.size() << '\n';

    for (int i = 0; i < words.size(); i++) {
        char* s = words.at(i);
        cout << s << ' ' << strlen(s) << " --\n";
    }

    cout << '\n';

    int wSize = words.size();
    for (int i = 0; i < wSize; i++) {
        for (int j = 0; j < wSize; j++) {
            //if (scmp(words[i], words[j], 0, 0, 0) == 1) { // words[i] > words[j]
            if (strcmp(words[i], words[j]) < 0) {
                c_str t = words[i];
                words[i] = words[j];
                words[j] = t;
            }
        }
    }

    for (int i = 0; i < words.size(); i++)
        cout << words[i] << " ---\n";
}
