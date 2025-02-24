
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <functional>

using namespace std;

static const char nl = '\n';

class Microbes final {
private:
    static const int lvl_c = 12;
    static const int max_lvl = lvl_c - 1;
    static constexpr const int lvls[lvl_c] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    static constexpr const char* fwd = "/home/admin/Desktop/work.dat";
    static constexpr const char* fwo = "/home/admin/Desktop/work.out";
    static const int xy = 5; //21;
    static const char m = 'x';
    static const int mn = 0;
    static const int my = lvls[0];
    static const char div = '|';

    int now[xy][xy] = { 0 };
    int now2[xy][xy] = { 0 };
    int gen = 0;

    typedef vector<char> vc;

public:

    Microbes() {
        int gens = 0;

        cout << "enter gens count: ";
        cin >> gens;
        cout << nl;

//        fillWd();
        crtGens(gens);
    }

    ~Microbes() = default;

private:

    static void fillWd() {
        FILE* f = fopen(fwd, "w");

        cout << (f == nullptr);

        srand(time(nullptr));
        for (int i = 0; i < xy; i++) {
            for (int j = 0; j < xy; j++) {
                if ((rand() % 2 + 1) == 1)
                    fputc((int) ' ', f);
                else
                    fputc((int) m, f);
                fflush(f);
            }
            if (i != xy - 1)
                fputc((int) nl, f);
            fflush(f);
        }
        fclose(f);
    }

    vc rf(const char* fn) {
        vector<char> r(0);

        FILE* f = fopen(fn, "r");

        if (f == nullptr) {
            fopen(fn, "w");
            return r;
        }

        int c = 0;
        int ct = 0;
        while ((c = fgetc(f)) != EOF) {
            r.push_back((char) c);
            ct++;
        }

        fclose(f);
        return r;
    }

    void genEvol() {
        int nExcl[xy][xy] = { 0 };

        for (int i = 0; i < xy; i++) {
            for (int j = 0; j < xy; j++) {
                int mic = now2[i][j];

                if (mic >= my && mic <= lvls[lvl_c - 2]) {
                    int nbrs = 0;

                    /*for (int i2 = i - 1; i2 <= i + 1; i2++) {

                        if ((i2 < 0) || (i2 >= xy))
                            continue;

                        for (int j2 = j - 1; j2 <= j + 1; j2++) {

                            if ((j2 < 0) || (j2 >= xy))
                                continue;

                            if (i2 == i && j2 == j)
                                continue;

                            cout << i2 << " " << j2 << nl;

                            if (now2[i2][j2] != mn)
                                nbrs++;
                        }
                    }
                    cout << "#\n";*/

                    /*
                     *
                     *  x x
                     *   X
                     *  x x
                     *
                     * */

                    if (i-1 >= 0 && now2[i-1][j] != mn)
                        nbrs++;
                    if (j-1 >= 0 && now2[i][j-1] != mn)
                        nbrs++;
                    if (j+1 < xy && now2[i][j+1] != mn)
                        nbrs++;
                    if (i+1 < xy && now2[i+1][j] != mn)
                        nbrs++;

//                    cout << "\ni=" << i << " j=" << j << " nbrs=" << nbrs << nl;
//                    prntGen();
//                    prntGen(1);

                    if (nbrs == 2 || nbrs == 3)
                        now[i][j] = now[i][j] + 1;
                    else {
                        //cout << "\ni=" << i << " nbrs=" << nbrs << " =" << now[i] << " =" << now2[i];
                        now[i][j] = mn;
                        nExcl[i][j] = my;
                    }
                }
            }
        }

        //cout << "\nwefwegf43g\n";

        for (int i = 0; i < xy; i++) {
            for (int j = 0; j < xy; j++) {

//            cout << "\n- i=" << i << " nbrs=" << now[i] << ' ' << nExcl[i] << nl;
//            prntGen();

                if (now[i][j] == mn && nExcl[i][j] == mn)
                    now[i][j] = my;
                else if (now[i][j] == lvls[11])
                    now[i][j] = mn;
            }
        }

        for (int i = 0; i < xy; i++) {
            for (int j = 0; j < xy; j++)
                now2[i][j] = now[i][j];
        }
    }

    int chkLivs() {
        int r = 0;

        for (int i = 0; i < xy; i++) {
            for (int j = 0; j < xy; j++) {
                if (now[i][j] != mn)
                    r++;
            }
        }
        return r;
    }

    void prntGen(int md = 0) {
        for (int i = 0; i < xy; i++) {
            for (int j = 0; j < xy; j++) {
                if (md == 0)
                    cout << now[i][j] << "  ";
                else
                    cout << now2[i][j] << "  ";
            }
            cout << nl;
        }
        cout << nl;
    }

    void crtGens(int gens) {
        vc smbls = rf(fwd);

        while (gen != gens) {

            if (gen == 0) {
                int j = 0;
                int k = 0;
                for (int i = 0; i < smbls.size(); i++) {
                    int r = mn;
                    if (smbls[i] == m)
                        r = my;
                    else if (smbls[i] == nl) {
                        j++;
                        k = 0;
                        continue;
                    }

                    now[j][k] = r;
                    now2[j][k] = r;

                    k++;
                }
            }

            cout << "before: gen: " << gen+1 << ", lives: " << chkLivs() << nl;
            prntGen();

            genEvol();

            int livs = chkLivs();
            cout << "after: gen: " << gen+1 << ", lives: " << livs << nl;
            prntGen();
            cout << nl;

            if (livs == 0)
                break;
            gen++;
        }
    }
};

class Monks final {
private:
    struct monk {
        int n;
        int* s;

        monk(int n, int* s) : n(n), s(s) {}

        ~monk() = default;
    };

    struct task {
        int n;
        int* m;

        task(int n, int* m) : n(n), m(m) {}

        ~task() = default;
    };

    static const int ms_l = 600;
    monk* ms[ms_l] = { nullptr };
    const int frst = 1;
    static const int s_l = 3;
    static constexpr const char* fn1 = "/home/admin/Desktop/monks.txt";
    static constexpr const char* fn2 = "/home/admin/Desktop/monks2.txt";
    int ms_mx = 0;
    static const int ts_l = 4;
    task* ts[ts_l] = { nullptr };

    typedef vector<char> vc;

public:
    Monks() {
        fillMs();
        fillTs();

        prnt(true);
        cout << nl;
        prnt(false);

        rnr();

//        fndmon(31);
//        fndprnt(34, 41);
    }

    ~Monks() = default;

private:

    static vc* rdFl(const char* fn) {
        FILE* f = fopen(fn, "r");

        if (f == nullptr)
            return nullptr;

        auto* chars = new vc(0);
        for (int i = fgetc(f); i != EOF; i = fgetc(f)) {
            char a = (char) i;

            if (a == nl)
                a = ' ';

            chars->push_back(a);
        }

        return chars;
    }

    static vector<int>* spltToIntBy(vc* chars, const char dil) {
        auto* dts = new vector<int>(0);
        char st[2] = { 0 };

        for (int i = 0, j = 0, k = 0; i < chars->size(); i++) {
            char chr = (*chars)[i];
            if (chr == dil) {
//                cout << '_' << st << ' ' << atoi(st) << nl;
                dts->push_back(atoi(st));

                st[0] = 0;
                st[1] = 0;

                j = 0;
            } else {
//                cout << "__" << j << ' ' << chr << nl;
                st[j] = chr;

                j++;
                k++;
            }
        }

        return dts;
    }

    void fillMs() {
        /*FILE* f = fopen(fn1, "r");

        if (f == nullptr)
            return;

        vector<char> chars = vector<char>(0);
        for (int i = fgetc(f); i != EOF; i = fgetc(f)) {
            char a = (char) i;

            if (a == nl)
                a = ' ';

            chars.push_back(a);
        }*/

        vc chars = *(rdFl(fn1));

        /*vector<int> dts = vector<int>(0);
        char st[2] = { 0 };
        for (int i = 0, j = 0, k = 0; i < chars.size(); i++) {
            if (chars[i] == ' ') {
                //cout << '_' << st << ' ' << atoi(st) << nl;
                dts.push_back(atoi(st));

                st[0] = 0;
                st[1] = 0;

                j = 0;
            } else {
                //cout << "__" << j << ' ' << chars[i] << nl;
                st[j] = chars[i];

                j++;
                k++;
            }
        }*/

        vector<int> dts = *(spltToIntBy(&chars, ' '));

        int* curSts;
        for (int i = 0, k = 0, l = 0; i < dts.size(); i++, l++) {
            int lk = 0;
            int n = 0;

            for (int j = 0; j <= s_l; j++) {
                if (j == 0) {
                    n = dts[i + j];
                    curSts = new int[s_l];
                    continue;
                }
                curSts[j - 1] = dts[i + j];
                lk = i + j;

                //cout << curSts[j] << ' ';
            }
            //cout << nl;

            //cout << curSts[0] << ' ' << curSts[1] << ' ' << curSts[2] << nl;

            ms[l] = new monk(n, curSts);
            ms_mx++;

            i = lk;
            k++;
        }
    }

    void fillTs() {
        vc chars = *(rdFl(fn2));
        vector<int> dts = *(spltToIntBy(&chars, ' '));
        int sz = dts.size();

        int* curMss;
        int lstI = 0;
        bool hasAdded = true;
        for (int i = 0, j = 0, n = -1, k = 0; i <= sz; i++) {
            if (hasAdded) {
                n = dts[i];
                curMss = new int[n];
                hasAdded = false;
//                cout << '_' << i << ' ' << j << ' ' << n << ' ' << dts[i] << nl;
                continue;
            }

            if (j < n) {
//                cout << "__" << i << ' ' << j << ' ' << n << ' ' << dts[i] << nl;
                curMss[j] = dts[i];
                j++;
            } else {
//                cout << "___" << i << ' ' << j << ' ' << n << ' ' << dts[i] << ' ' << lstI << ' ' << k << nl;

                ts[k] = new task(n, curMss);

                if (i == sz)
                    break;

                k++;
                i = lstI;
                j = 0;
                hasAdded = true;
            }
            lstI = i;
        }
    }

    void prnt(bool b) {
        if (b) {
            for (int i = 0; i < ms_l; i++) {
                monk* m = ms[i];

                if (m == nullptr)
                    break;

                cout << m->n << ' ';

                int *sts = m->s;

                for (int j = 0; j < s_l; j++)
                    cout << sts[j] << " | ";
                cout << nl;
            }
        } else {
            for (int i = 0; i < ts_l; i++) {
                task* t = ts[i];

                if (t == nullptr)
                    break;

                int n = t->n;
                cout << n << ' ';

                int* sts = t->m;

                for (int j = 0; j < n; j++)
                    cout << sts[j] << " | ";
                cout << nl;
            }
        }
    }

    void rnr() {
        cout << nl;

        for (int i = 0; i < ts_l; i++) {
            task t = *(ts[i]);
            int tn = t.n;
            int tm1 = t.m[0];
            int tm2 = t.m[1];

            if (tn == 1)
                fndmon(tm1);
            else
                fndprnt(tm1, tm2);
        }
    }

    vector<int> fndmon(int n, bool prnt = true) {
        vector<int> r;

        if (prnt)
            cout << "n: " << n << " prnts: ";

        for (int i = 0, lstTch = -1;; i++) {
            monk m = *(ms[i]);

            for (int j = 0; j < s_l; j++) {
                int* sts = m.s;

                if (sts[j] == n) {
                    lstTch = m.n;
                    break;
                }
            }

            if (lstTch != -1 && lstTch != n) {
                n = lstTch;
                r.push_back(n);

                if (prnt)
                    cout << n << ' ';
            }

            if (m.n == frst)
                break;
        }
        cout << nl;
        return r;
    }

    void fndprnt(int n1, int n2) {
        vector<int> n1s = fndmon(n1, false);
        vector<int> n2s = fndmon(n2, false);
        int n1sz = n1s.size();
        int n2sz = n2s.size();

        /*for (int i = 0; i < n1sz; i++)
            cout << "__" << n1s[i];
        cout << nl;

        for (int i = 0; i < n2sz; i++)
            cout << "__" << n2s[i];
        cout << nl;*/

        int prnt = 0;
        for (int i = 0; i < n1sz; i++) {
            int n1t = n1s[i];

            for (int j = 0; j < n2sz; j++) {
                if (n1t == n2s[j] && n1t != frst)
                    prnt = n1t;
            }
        }

        cout << n1 << " & " << n2 << " : " << prnt;
    }
};

void hanoi() {
    const int size = 4;

    function<void(int, int, int, int)> shft;
    shft = [size, shft](int n, int from, int to, int tmp) -> void {
                if (n == 0)
                    return;

                shft(n - 1, from, tmp, to);
                cout << from << " => " << to << nl;
                shft(n - 1, tmp, to, from);
           };

    shft(size, 1, 3, 2);
}

class ShellSort final {
    static const int size = 14;
    int arr[size] = { 32, 95, 16, 82, 24, 66, 35, 19, 75, 54, 40, 43, 93, 68 };

public:

    void sort() {
        int step, i, j, tmp;

        for (step = size / 2; step > 0; step /= 2) {
            for (i = step; i < size; i++) {
                for (j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step) {
                    tmp = arr[j];
                    arr[j] = arr[j + step];
                    arr[j + step] = tmp;
                }
            }
        }
    }

    ShellSort() {
        sort();
        for (int i = 0; i < size; i++)
            cout << arr[i] << ' ';
    }
    ~ShellSort() = default;
};

int main() {
//    Microbes();
//    Monks();
    Hanoi();
//    ShellSort();
    return 0;
}
