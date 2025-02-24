

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

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
    static const char nl = '\n';

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

int main() {
    Microbes();
    return 0;
}
