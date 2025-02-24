#include <stdio.h>
#include <stdlib.h>

/*
 * Author: Vad Nik.
 */

// Task 1 begin:
int addToInt(const int numb, const int num) {
    unsigned pow = 10;
    while(num >= pow)
        pow *= 10;
    return numb * pow + num;
}

int v = 128;
int res = 0b0;
int count = 1;
int task1(int num) {
    if(num >= v) {
        res = addToInt(res, 1);
        num -= v;
    } else
        res = addToInt(res, 0);
    v /= 2;

    count++;
    if (count > 8)
        return res;
    task1(num);

    return res;
}
// Task 1 end.

int task2(const int a, const int b) {
    if (a == 0 || b == 0)
        return 0;
    if (a == 1 || b == 1)
        return 1;

    int res = 0;
    for (int i = 1; i < b; i++) {
        if (res == 0)
            res = a * a;
        else
            res *= a;
    }
    return res;
}

// Task 2 hard begin:
int res2 = 0;
int count2 = 1;
int task2H(const int a, const int b) {
    if (a == 0 || b == 0)
        return 0;
    if (a == 1 || b == 1)
        return 1;

    if (res2 == 0)
        res2 = a * a;
    else
        res2 *= a;

    count2++;
    if (count2 == b)
        return res2;
    task2H(a, b);

    return res2;
}
// Task 2 hard end.

unsigned int task3(const unsigned int a, const unsigned int expected) {
    if (a > expected)
        return 0;
    if (a == expected)
        return 1;

    unsigned int res = task3(a+1, expected);
    if (a)
        res += task3(a*2, expected);

    return res;
}

int main(const int argc, const char* argv[]) {

    printf("Task 1: %d\n", task1(25));
    printf("Task 2: %d\n", task2(5, 3));
    printf("Task 2 hard: %d\n", task2H(5, 3));
    printf("Task 3: %d\n", task3(3, 20));

    return EXIT_SUCCESS;
}