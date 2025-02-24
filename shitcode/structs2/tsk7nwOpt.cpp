
#include <cstdio>
#include "../a.h"

unsigned cmps = 0;
#define __cmp cmps++;

void lnch() {
    const int ln = 3;
    int a[ln][ln] = {
            { 2, 1, 3 },
            { 4, 0, 1 },
            { 1, 2, 7 }
    };
//    int a[N][N] = {
//            { 1, 2, 3 },
//            { 4, 5, 6 },
//            { 7, 8, 9 }
//    };
//    int a[N][N] = {
//            { 9, 8, 7 },
//            { 6, 5, 4 },
//            { 3, 2, 1 }
//    };

    int d[ln][ln] = { 0 };

    for(int y = ln - 1; y >= 0; y--) {
        for(int x = 0; x < ln; x++) {
            d[y][x] = a[y][x];

            int v = 0;

            if (x - 1 >= 0)
                v = d[y][x - 1];

            if (y + 1 < ln)
                v = d[y + 1][x];

            if (x - 1 >= 0 && y + 1 < ln)
                v = d[y][x - 1] < d[y + 1][x] ? d[y][x - 1] : d[y + 1][x];

            __cmp

            d[y][x] += v;

            for (int i = 0; i < ln; i++) {
                for (int j = 0; j < ln; j++)
                    printf("%d ", d[i][j]);
                printf("\n");
            }
            printf("\n");
        }
    }
    printf("# %d %u\n", d[0][ln - 1], cmps);
}
