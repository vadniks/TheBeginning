
// Variant 6

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <chrono>
#include "a.h"

typedef char* str;
typedef const char chr;
typedef chr* ctr;
typedef const int cnt;

ctr af = "a.txt";
ctr bf = "b.txt";
ctr cf = "c.txt";
cnt bfr = 1000000;
chr spc = ' ';
chr dot = '.';
chr cma = ',';
cnt soc = sizeof(char);

unsigned int scs = 0; // amount of successful comparisons
unsigned int flr = 0; // amount of unsuccessful comparisons

// lambda for incrementing (un)successful (depending on 'a') comparisons amount
#define cnt(a, b...) \
    [b]() { (a) ? scs++ : flr++; }()

// structure containing 2 items with types which
// are chosen by the user of this structure
template<typename t1, typename t2>
struct pr {
    t1 a;
    t2 b;

    // constructor initializing variables
    pr(t1 a, t2 b) : a(a), b(b) {}

    // destruction is handled by the user of this structure
};
typedef pr<str, int> prci;

// read a file
prci* rdf(ctr fn /*file*/) {
    if (!fn) throw 1; // quit if the file name is null

    str s = 0; // buffer for the file's content
    FILE* f = fopen(fn, "r"); // initialize the file
    if (!f) return 0; // if the file hasn't been found quit

    int i, j; // counter and buffer for the next char
    // iterate until the cursor reaches end of file
    for (i = 0, j = 0; i <= bfr; i++) {
        j = fgetc(f); // read next character
        if (j == EOF) break; // quit if the end of file reached

        s = (str) realloc(s, soc * (i + 1)); // grow buffer
        s[i] = (char) j; // assign the next char to the next buffer's cell
    }

    return !i ? 0 : new pr(s, i); // return a pair of the buffer and it's size
}

// task 1
void tsk1(prci* pr/*string and it's length*/) {
    ctr org = pr->a; // original string
    cnt oln = pr->b; // original size
    delete pr; // free memory

    str nw = 0; // declare the buffer for the altered string
    int j = 0; // size of the buffer
    char t = 0; // buffer for the next character
    for (int i = 0; i < oln; i++) { // iterate through the whole original string
        t = org[i]; // read next character

        if (t == cma) { // if the character equals to ','
            nw = (str) realloc(nw, soc * (j + 1)); // grow the buffer
            nw[j++] = spc; // assign the next character to the next cell of the buffer
            // and increment the buffer's size

            cnt(1); // increment the successful comparisons amount
        } else if (t == dot) { // if the character equals to '.'
            nw = (str) realloc(nw, soc * (j + 2)); // grow the buffer
            nw[j++] = spc; // assign ' ' to the buffer and increment size 2 times
            nw[j++] = spc;

            cnt(1); // increment the successful comparisons amount
        } else { // in all other cases
            nw = (str) realloc(nw, soc * (j + 1)); // grow the buffer
            nw[j++] = t; // assign the next character to the buffer and increment it's size

            cnt(0); // increment the unsuccessful comparisons amount
        }
    }
    delete org; // free the memory used by original string

    printf("|%s|\n", nw); // print the altered string
    free(nw); // free the altered string
}

// task 2
void tsk2(ctr a /*a string*/) {
    if (!a) throw 1; // quit if the string is null

    cnt b = (int) strlen(a); // size of the string
    int* c = new int[b]; // array of integers

    str d = 0; // buffer for the next prefix
    bool n = 1; // buffer for the equality check
    for (int i = 0 /*lower anchor index*/,
            j /*next char index*/,
            k /*upper anchor index*/,
            l /*next prefix/postfix char index*/,
            m /*next always-zero-starting char index*/;
        i < b; i++) { // iterate through the whole string

        // iterate from '0' index to 'i', incrementing j index
        // and decrement the k starting with ${i + 1} for each iteration
        for (j = 0, k = i + 1/*= b - (b - i) + 1*/; j <= i; j++, k--) {
            d = new char[j + 1]; // create a new string prefix buffer

            // prefix of the whole string:
            for (l = 0; l < j; l++) {// iterate through the buffer
                d[l] = a[l]; // assign the next string's character to the next buffer's cell
                // printf("%c", a[l]);
            }
            // printf("\n    ");
            // suffix of the whole string:
            // iterate starting from the upper anchor character
            // to the character located
            // right after the lower anchor character
            for (l = k, m = 0; l < k + j; l++, m++) {
                n &= d[m] == a[l]; // assign the result of the characters'
                                   // equality check to the equality buffer
                // printf("%c", a[l]);
            }
            // printf("\n%d %d %d\n", i, j, k);
            cnt(n and j > 0, n, j); // increment the (un)successful (depending on the 'n') comparisons amount

            if (n) // if the equality buffer is true
                c[i] = j; // assign the next char index, which stands for ${prefix length} - 1,
                          // to the integer array's cell with index of the lower anchor char index
            else // if the equality buffer is false
                n = 1; // reset it
            delete[] d; // free the new buffer
        }
        // printf("--\n");
    }

    // iterate through the integers array
    for (int i = 0; i < b; i++)
        printf("%d ", c[i]); // print each it's cell
    printf("\n"); // add the new line mark to the stdout

    // iterate through the string
    for (int i = 0; i < b; i++)
        printf("%c ", a[i]); // print each char
    printf("\n"); // add the new line mark to the stdout

    delete[] c; // free memory allocated for the integer array
}

// gets amount of time function worked
template<typename t>
void drt(t a/*parameter of the function*/, void (&b)(t) /*function pointer*/) {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration;

    auto t1 = high_resolution_clock::now();
    b(a); // <-- call the function with it's parameter
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> c = t2 - t1;
    printf("Time the function worked: %g\n", c.count());
}

void lnch() {
    auto pr = rdf(bf);
    drt(pr, tsk1);
    printf("Successful = %d unsuccessful = %d\n", scs, flr);

    scs = 0;
    flr = 0;
    printf("\n");

//    drt("aabcdaahia", tsk2);
//    drt("abcdefghi", tsk2);
//    drt("AABAACAABAAAABAACAABAA", tsk2);
    // drt("abca", tsk2);
    // drt("abcdabscabcdabia", tsk2);
    drt("abcdefghiaabcdaahiazwfsaqfeffesqvtrdebhytjfr", tsk2);

    printf("Successful = %d unsuccessful = %d\n", scs, flr);
}
