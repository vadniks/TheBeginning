/*
Console version of the 2048 game.
Designed specially for GNU/Linux terminal.
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>

using namespace std;

typedef const int cnst_i;
typedef const char cnst_c;
typedef int* i_arr;

#define FORI(i0, i1, i) for (int i = i0; i < i1; i++)
#define FORI2(i0, i1, i, j0, j1, j) FORI(i0, i1, i) FORI(j0, j1, j)

#define FORI_(i0, i1, i) for (int i = i0-1; i >= i1; i--)
#define FORI2_(i0, i1, i, j0, j1, j) FORI(i0, i1, i) FORI(j0, j1, j)

class G2048 final {
private:
    cnst_i elems_sz = 4;
    cnst_i num_elem_sz = elems_sz;
    cnst_i elem_empty = 0;
    cnst_i basic_elem = 2;

    cnst_c sc = ' ';
    cnst_c nl = '\n';
    cnst_c dh = '-';
    cnst_c dv = '|';
    cnst_c dn = sc;

    static cnst_c up = 'w';
    static cnst_c dw = 's';
    static cnst_c lf = 'a';
    static cnst_c rt = 'd';
    static cnst_c ex = 'q';

    static cnst_c up_ = 'W';
    static cnst_c dw_ = 'S';
    static cnst_c lf_ = 'A';
    static cnst_c rt_ = 'D';
    static cnst_c ex_ = 'Q';

    i_arr* elems;
    i_arr* elems_aft_mv;

    bool isGameOver = false;
    char move = 0;
    int score = 0;

public:

    G2048() {
        elems = new int*[elems_sz];
        FORI(0, elems_sz, i)
            elems[i] = new int[elems_sz];

        elems_aft_mv = new int*[elems_sz];
        FORI(0, elems_sz, i)
            elems_aft_mv[i] = new int[elems_sz];

        cycle();
    }

    ~G2048() = default;

private:

    void cycle() {
        srand(time(nullptr));

        while (move != ex && !isGameOver) {
            if (move == 0 || move == up || move == dw || move == lf || move == rt)
                genBasicSmWhr();
            drawFrame();

            printf("enter move (w, s, a, d): ");
            fflush(stdout);

            cin >> move;

            if (move == ex_)
                genBasicSmWhr();
            else
                moveTreat();
        }
    }

    void moveTreat() {
        FORI2(0, elems_sz, i, 0, elems_sz, j)
                elems_aft_mv[i][j] = elem_empty;

        if (move == up || move == up_)
            treatUpCtrl();
        else if (move == dw || move == dw_)
            treatDwCtrl();
        else if (move == lf || move == lf_)
            treatLfCtrl();
        else if (move == rt || move == rt_)
            treatRtCtrl();

        FORI2(0, elems_sz, i, 0, elems_sz, j)
            elems_aft_mv[i][j] = elem_empty;

        cout << "score: " << score << nl;
    }

    void treatUpCtrl() {
        FORI(0, elems_sz, i) {
            FORI(0, elems_sz, j) {
                int elem = elems[i][j];

                if (elem != elem_empty)
                    treatUp(i, j, elem, elem);
            }
        }
    }

    void treatUp(int i, int j, int sum, int elem) {
        int nextElemY = i - 1;
        bool hasSummed = false;
        while (nextElemY > -1) {
            int elAftMv = elems_aft_mv[nextElemY][j];
            if (elems[nextElemY][j] == elem && (elAftMv == elem || elAftMv == elem_empty)) {
                sum += elem;
                elems[nextElemY][j] = elem_empty;
                hasSummed = true;
            } else if (elems[nextElemY][j] != elem_empty)
                break;

            nextElemY--;
        }

        elems[i][j] = elem_empty;
        elems[nextElemY + 1][j] = sum;

        if (hasSummed)
            score += sum;

        elems_aft_mv[nextElemY + 1][j] = elem;
    }

    void treatDwCtrl() {
        FORI_(elems_sz, 0, i) {
            FORI(0, elems_sz, j) {
                int elem = elems[i][j];

                if (elem != elem_empty)
                    treatDw(i, j, elem, elem);
            }
        }
    }

    void treatDw(int i, int j, int sum, int elem) {
        int nextElemY = i + 1;
        bool hasSummed = false;

        while (nextElemY < elems_sz) {
            int elAftMv = elems_aft_mv[nextElemY][j];
            if (elems[nextElemY][j] == elem && (elAftMv == elem || elAftMv == elem_empty)) {
                sum += elem;
                elems[nextElemY][j] = elem_empty;
                hasSummed = true;
            } else if (elems[nextElemY][j] != elem_empty)
                break;

            nextElemY++;
        }

        elems[i][j] = elem_empty;
        elems[nextElemY - 1][j] = sum;

        if (hasSummed)
            score += sum;

        elems_aft_mv[nextElemY - 1][j] = elem;
    }

    void treatLfCtrl() {
        FORI(0, elems_sz, i) {
            FORI(0, elems_sz, j) {
                int elem = elems[i][j];

                if (elem != elem_empty)
                    treatLf(i, j, elem, elem);
            }
        }
    }

    void treatLf(int i, int j, int sum, int elem) {
        int nextElemX = j - 1;
        bool hasSummed = false;

        while (nextElemX > -1) {
            int elAftMv = elems_aft_mv[i][nextElemX];
            if (elems[i][nextElemX] == elem && (elAftMv == elem || elAftMv == elem_empty)) {
                sum += elem;
                elems[i][nextElemX] = elem_empty;
                hasSummed = true;
            } else if (elems[i][nextElemX] != elem_empty)
                break;

            nextElemX--;
        }

        elems[i][j] = elem_empty;
        elems[i][nextElemX + 1] = sum;

        if (hasSummed)
            score += sum;

        elems_aft_mv[i][nextElemX + 1] = elem;
    }

    void treatRtCtrl() {
        FORI(0, elems_sz, i) {
            FORI_(elems_sz, 0, j) {
                int elem = elems[i][j];

                if (elem != elem_empty)
                    treatRt(i, j, elem, elem);
            }
        }
    }

    void treatRt(int i, int j, int sum, int elem) {
        int nextElemX = j + 1;
        bool hasSummed = false;
        while (nextElemX < elems_sz) {
            int elAftMv = elems_aft_mv[i][nextElemX];
            if (elems[i][nextElemX] == elem && (elAftMv == elem || elAftMv == elem_empty)) {
                sum += elem;
                elems[i][nextElemX] = elem_empty;
                hasSummed = true;
            } else if (elems[i][nextElemX] != elem_empty)
                break;

            nextElemX++;
        }

        elems[i][j] = elem_empty;
        elems[i][nextElemX - 1] = sum;

        if (hasSummed)
            score += sum;

        elems_aft_mv[i][nextElemX - 1] = elem;
    }

    void genBasicSmWhr(int lastY = 0, int lastX = 0, int step = 0) {
        if (lastY == elems_sz) {
            isGameOver = true;
            return;
        }

        if (lastX == elems_sz)
            genBasicSmWhr(lastY + 1, 0);

        int newElemX = rand() % elems_sz;
        int newElemY = rand() % elems_sz;

        FORI2(lastY, elems_sz, i, lastX, elems_sz, j) {
            if (i == newElemY && j == newElemX) {
                if (elems[i][j] == elem_empty)
                    elems[i][j] = basic_elem;
                else
                    genBasicSmWhr(i, j, step);
            }
        }

        if (step != 1)
            genBasicSmWhr(0, 0, 1);
    }

    void drawFrame() {
        cout << "\033[H\033[J";

        int map_x = num_elem_sz * elems_sz + 2 + 4;

        FORI(0, map_x, k)
            pc(dh);
        pc(nl);

        FORI(0, elems_sz, i) {
            pc(dv);

            FORI(0, elems_sz, j) {
                int elem = elems[i][j];
                int nsz = (elem != 0) ? getNumSize(elem) : 1;

                FORI(0, num_elem_sz - nsz, k)
                    pc(dn);

                char *buf = new char[num_elem_sz];
                sprintf(buf, "%d", elem);

                    if (elem != 0)
                        cout << "\033[32;1;1m" << buf << "\033[0m";
                    else
                        cout << buf;

                pc(sc);
            }

            pc(dv);
            pc(nl);
        }

        FORI(0, map_x, k)
            pc(dh);

        pc(nl);
    }

    static inline void pc(char c) { putchar(c); }

    static int getNumSize(int n) {
        int res = 0;

        while (n != 0) {
            res++;
            n /= 10;
        }

        return res;
    }
};

int main() {
    G2048();
    return 0;
}
