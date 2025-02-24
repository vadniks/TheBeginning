
// Variant 5

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <chrono>
#include "a.h"

#pragma ide diagnostic ignored "bugprone-reserved-identifier"
#pragma ide diagnostic ignored "modernize-use-nullptr"
#pragma ide diagnostic ignored "modernize-use-bool-literals"
#pragma ide diagnostic ignored "DanglingPointer"
#pragma ide diagnostic ignored "UnusedValue"

typedef char* str;
typedef const char chr;
typedef chr* ctr;
typedef const int cnt;
typedef unsigned int unt;
typedef void* vdp;

unt _cna = 0; // amout of first pattern successful comparisons
unt _cns = 0; // amount of all pattern successful comparisons
unt _cnf = 0; // amount of all pattern unsuccessful comparisons
// labda for counting
#define _cnt(_a, _b...) [_b]() -> bool { _a ? _cns++ : _cnf++; return _a; }()
#define _cnr _cna = 0, _cns = 0, _cnf = 0; // reset counters

        //  x    x          x          x                        x     x     x
ctr aa = "Word0 wrd1 word2 wrd1 word4 word0 word3 word9 word8 word0 word5 word5.";
        //  x    x          x           x                       x
ctr bb = "Word0 wrd1 word2 wrd1 word4 word0 word3 word9 word8 word0 word6 word5.";
ctr cc = "Wowd0 wwd1 word2 wwd1 word4 wowd0 word3 word9 word8 wowd0 word6 aaaa5.";

        //  x    x           x         x                        x     x     x    x
ctr dd = "Word0 wrd1 word2 wrd1 word4 word0 word3 word9 word8 word0 word5 word5 wrd1 "
        //       x            x                          x
         "word1 wrd1 word11 word0 word12 word13 word14 word0 word15 word16.";

        //  x    x          x           x                       x     x     x    x
ctr ee = "Word0 wrd1 word2 wrd1 word4 word0 word3 word9 word8 word0 word5 word5 wrd1 "
        //        x           x                          x
         "word1 wrd1 word11 word0 word12 word13 word14 word0 word15 word16 word17 "
        //  x      x             x     x     x
         "wowd0 word20 word19 word20 wowd0 word20 aaaa5.";

chr sp = ' ', en = '\0', dt = '.';
cnt soc = sizeof(char);

void t1(ctr a/*text*/) {
    unt 
        i = 0, /*text's next char index*/
        j = 0, /*next word's next char index*/
        k = 0, /*next text's comparsion char index*/
        l = 0, /*next word's next comparsion char index*/
        m = 0, /*amout of the same words as the next one which are presented in the text*/
        n = 0, /*space formatter flag*/
        o = 0; /*buffer for the 'm'*/
    str b = 0; /*word buffer*/
    char c = 0; /*next text's char buffer*/
    bool f = 1; /*word equality buffer*/

    for (i = 0;; i++) { // keep looping until the end of the text is reached
        c = a[i]; // take the next text's char

        if (c == sp or c == dt) { // if space or dot is reached
            f = 1; // reset the word equality buffer
            // keep comparing word chars with the text ones until
            // the end of the text reached
            for (k = 0, l = 0, m = 0, o = 0;; k++) {
                // if space of dot is reached
                if (a[k] == sp or a[k] == dt) {
                    o = m; // save the value of 'm'

                    // if the word is found in the text again
                    // increase the 'm' counter
                    m += _cnt(j == l and f, j, l, f) ? 1 : 0;
                    l = 0; // reset the 'l'

                    // if the word was found first time
                    if (m == 1 and o == 0)
                        _cna++; // increase counter

                    // if the next text's char isn't dot
                    if (a[k] != dt) {
                        f = 1; // reset the 'f' buffer
                        continue;
                    } else { // if it's dot
                        f = m > 1; // if the word was found more than one time set the buffer to true
                        break; // end inner looping
                    }
                }

                // compare word's next char with the text's one
                f &= tolower(a[k]) == tolower(l >= j ? '#' : b[l]);
                l++; // set word's char index points to the next word's char
            }

            if (!f) { // if the word was found only once in the text
                b[j] = en; // add end of string mark to the word buffer

                if (n) printf(" "); // format the output
                else b[0] = (char) toupper(b[0]);

                printf("%s", b); // output the unique word
                n = 1; // set the space formatter flag to true
            }

            free(b); // free up the memory allocated for the next word
            b = 0; // reset indexes
            j = 0;

            if (c == dt) break; // if the end of the string is reached
            else continue;
        }

        // grow word's buffer
        b = (str) realloc(b, soc * (j + 1));
        b[j++] = c; // put next text's char into it
    }
    printf(".\n"); // format the output
}

unt* t2_1(ctr a /*a string*/, unt b /* size of the string */) {
    unt* c = new unt[b]; // array of integers

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
            for (l = 0; l < j; l++) // iterate through the buffer
                d[l] = a[l]; // assign the next string's character to the next buffer's cell

            // suffix of the whole string:
            // iterate starting from the upper anchor character
            // to the character located
            // right after the lower anchor character
            for (l = k, m = 0; l < k + j; l++, m++)
                n &= d[m] == a[l]; // assign the result of the characters'
            // equality check to the equality buffer

            if (n) // if the equality buffer is true
                c[i] = j; // assign the next char index, which stands for ${prefix length} - 1,
                // to the integer array's cell with index of the lower anchor char index
            else // if the equality buffer is false
                n = 1; // reset it
            delete[] d; // free the new buffer
        }
    }
    return c;
}

template<typename t> // callback parameter type
void t2_2(
    ctr a/*text*/, 
    ctr b/*word to search for*/, 
    unt al/*text length*/, 
    unt bl/*word length*/, 
    unt* prs/*array of the longest prefixes*/, 
    t c/*callback parameter*/, 
    void (*d)(t)/*callback*/
) {
    bool e = 0; // word first found buffer
    // iterate through the text until its end is reached
    for (unt i = 0, j = 0; i < al;) {
        // compare text's char with the pattern's one
        if (tolower(a[i]) == tolower(b[j]))
            i++, j++; // increase indexes

        if (j == bl) { // if the word's next char index is equal to its
            // length then all word's letters are equal to the
            // previous piece of the text and the word itself is equal to
            // that piece

            // if the next text's char is space or dot then the end of
            // the word is reached and the same word is found in the text
            if (a[i] == sp or a[i] == dt) {
                if (!e) _cna++, e = 1; // if it's found first time
                                        // increase the counter
                _cnt(1); // successful comparisons

                d(c); // invoke the callback
            }

            j = prs[j - 1]; // shift the next word's char index
                            // according to array of prefixes
        } else if (i < al and tolower(a[i]) != tolower(b[j]))
            // if the end of the text isn't reached and text's and
            // word's chars aren't equal

            // if the word's next char index isn't 0 then shift it
            // otherwise point the text's next char index to the next one
            j ? j = prs[j - 1] : i++;
    }
}

void t2_3(ctr a/*text*/, unt b/*its length*/) {
    char c = 0; // next char buffer
    str d = 0; // next word buffer
    unt* e = 0; // next array of the longest prefixes buffer
    for (unt i = 0, j = 0, k = 0, l = 0; i < b; i++) {
        c = a[i]; // take the next char

        // if the end of the word is reached
        if (c == sp or c == dt) {
            d[j] = en; // add end mark to the word buffer

            e = t2_1(d, j); // calculate prefix function
            // find how many times this word is present in the text
            t2_2<unt*>(a, d, b, j, e, &k, [](unt* _a) { ++*_a; });

            if (k <= 1) // if the word is present less then 2 times
                !l ? d[0] = (char) toupper(d[0]) : l,
                l ? printf(" ") : int(),
                printf("%s", d), // format the output and print the word
                l++; // chage the formatter flag
            k = 0; // reset the word presence amount buffer

            // reset the word buffer index and free up the memory
            j = 0, free(d), d = 0, free(e);
        } else { // if next char isn't space or dot
            // grow the buffer
            d = (str) realloc(d, soc * ++j);
            d[j - 1] = c; // add next char
        }
    }
    printf(".\n"); // format the output
}

// gets amount of time function worked
void drt(vdp a/*additional function parameter*/, void (*b)(vdp)) {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration;

    auto t1 = high_resolution_clock::now();
    b(a); // <--
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> c = t2 - t1;
    printf("Time the function worked: %g\n", c.count());
}

void lnch() {
    drt(0, [](vdp _) { t1(aa); });
    printf("Successes: %d, Failures: %d, Firsts: %d\n\n", _cns, _cnf, _cna);
    _cnr

    drt(0, [](vdp _) { t1(bb); });
    printf("Successes: %d, Failures: %d, Firsts: %d\n\n", _cns, _cnf, _cna);
    _cnr

    drt(0, [](vdp _) { t1(cc); });
    printf("Successes: %d, Failures: %d, Firsts: %d\n\n", _cns, _cnf, _cna);
    _cnr

    printf("1----\n");

    drt(0, [](vdp _) { t2_3(aa, strlen(aa)); });
    printf("Successes: %d, Failures: %d, Firsts: %d\n\n", _cns, _cna * _cna - _cns, _cna);
    _cnr

    drt(0, [](vdp _) { t2_3(bb, strlen(bb)); });
    printf("Successes: %d, Failures: %d, Firsts: %d\n\n", _cns, _cna * _cna - _cns, _cna);
    _cnr

    drt(0, [](vdp _) { t2_3(cc, strlen(cc)); });
    printf("Successes: %d, Failures: %d, Firsts: %d\n\n", _cns, _cna * _cna - _cns, _cna);
    _cnr

    printf("2----\n");

    drt(0, [](vdp _) { t1(dd); });
    printf("Successes: %d, Failures: %d, Firsts: %d\n\n", _cns, _cnf, _cna);
    _cnr

    drt(0, [](vdp _) { t1(ee); });
    printf("Successes: %d, Failures: %d, Firsts: %d\n\n", _cns, _cnf, _cna);
    _cnr

    printf("3----\n");

    drt(0, [](vdp _) { t2_3(dd, strlen(dd)); });
    printf("Successes: %d, Failures: %d, Firsts: %d\n\n", _cns, _cna * _cna - _cns, _cna);
    _cnr

    drt(0, [](vdp _) { t2_3(ee, strlen(ee)); });
    printf("Successes: %d, Failures: %d, Firsts: %d\n\n", _cns, _cna * _cna - _cns, _cna);
    _cnr
}
