/*
 * Structs 1. linux64, GCC std=20
 */

#include <iostream>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>

using namespace std;

typedef unsigned char bte;
typedef unsigned long uln;

// does exactly what the task wants
void task1a() {
    bte a = 255;
    bte b = 1;

    a = a & (~(b << 4));
    cout << (int) a << endl;
}

// like the previous one but the bit is different
void task1b() {
    bte a = 239;

    // 239 = 11101111
    // ~~~   87654321
    // 175 = 10101111
    // ~~~~~~~^

    a = a & (~(1 << 6));
    cout << (int) a << endl;
}

// copied from the task without influencing changes
void task1c() {
    unsigned int x = 25;
    const int n = sizeof(int) * 8;
    unsigned m = 1 << (n - 1);

    cout << "start " << bitset<n>(m) << endl;
    cout << "result: ";

    for (int i = 1; i <= n; i++) {
        //cout << "__" << (x & m) << ' ' << bitset<n>(m) << ' ' << n - i << ' ' << i << ' ' << (m >> 1);
        cout << ((x & m) >> (n - i));
        //       ~~~^ checks if the chosen bit is '1'
        //                  ~~~^ calculates position number
        //            ~~~^ shifts the chosen bit into the first position of the bitset
        //                 thus makes the output be the only one bit '0' or '1'

        m = m >> 1; // shifts the mask to continue checking each bit
    }
    cout << endl;
    // This function splits the original number into bits which then are being outputted
    // in the same order thus makes the total output looks like the original number in binary
    // form that contains 32 bits in total.
}

template<typename t> // lets usage of different numeric types
void task2ab(const int sz) { // sz - number of numbers to enter and to operate with
    const t len = sizeof(t) * 8;
    if (sz > len) throw 1; // NOLINT

    t arr = 0; // binary array

    // entering numbers and associate them with the array's bits
    // (which are considered as elements)
    t d = 0;
    for (int i = 0, c = 0; i < sz; i++) {
        cin >> c;
        if (c >= len || c < 0) throw 1; // NOLINT

        d = ((t) 1) << c;
        if (arr & d) // clones check
            continue;

        arr ^= d;
    }
    cout << "arr: " << bitset<len>(arr) << endl; // outputting current state of the array

    // sorting i.e. continuously checking for the number presence in
    // each bit (element) of the array and outputting each element's number
    // with confirmed number presence
    for (int i = 0; i < len; i++) {
        if (arr & ((t) 1) << i)
            cout << i << ' ';
    }
    cout << endl;
}

// just like the previous with extended array length
void task2c(const uln len, const uln sz) {
    bte* arr = (bte*) calloc(sizeof(bte), len);

    for (uln i = 0, c = 0; i < sz; i++) {
        cin >> c;
        if (c >= len) throw 1; // NOLINT

        arr[c] = 1;
    }

    for (uln i = 0; i < len; i++) {
        if (arr[i])
            cout << i << ' ';
    }
    cout << endl;
}

//#pragma message("change the path below (110 line)")

const char* fnm = "/home/admin/Downloads/task3a.txt";
const char* fnm2 = "/home/admin/Downloads/task3a1.txt";
const int n3a = 1000000; // 7 mb
//const int nn3a = n3a / 5; // 1.4 mb

// generates file with random numbers, ignore this
[[deprecated("contains clones")]]
void task3a0() {
    FILE* f = fopen(fnm, "wb");
    if (!f) throw 1; // NOLINT

    srand(time(0)); // NOLINT
    int tmp = 0;
    for (int i = 0; i < n3a; i++) {
        tmp = n3a + rand() % 8000000; // NOLINT, RAND_MAX = INT_MAX
        cout << tmp << endl;
        fwrite(&tmp, sizeof(bte), 7, f);
    }
    fclose(f);
}

// generates a large amount of big random shuffled numbers
void task3a1() {
    vector<int> arr(n3a); // temporary array

    // generating sorted big numbers
    for (int i = n3a, j = 0; i < n3a * 10 - 1 and j < n3a; i++, j++)
        arr[j] = i;

    // random shuffle the numbers thus makes them be unsorted
    //shuffle(begin(arr), end(arr), std::mt19937(std::random_device()()));

    FILE* f = fopen(fnm, "wb");
    if (!f) throw 1; // NOLINT

    // write the unsorted numbers to the binary file
    for (int i = 0; i < n3a; i++) {
        cout << arr[i] << endl;
        fwrite(&arr[i], sizeof(int), 1, f);
    }
}

// reads and sorts many big numbers
void task3a() {
    FILE* f = fopen(fnm, "rb");
    if (!f) throw 1; // NOLINT

    //bte* arr = (bte*) calloc(n3a * 10, sizeof(bte));
    //if (!arr) throw 1; // NOLINT
    auto* arr = new bitset<n3a * 10>(); // extra large binary array

    // buffer which is the array's index too
    int tmp = 0; //int b = 0;
    for (int i = 0; i < n3a; i++) { // reading all numbers
        fread(&tmp, sizeof(int), 1, f); // consider each number as the array index
        //cout << "_" << tmp << endl; // unsorted array
        //arr[tmp] = 1;
        //if (arr[tmp])
        //    b++;
        arr->set(tmp); // set the indexed element (bit) to '1'

//        if (tmp == 8999975)
//            return;
    }
    fclose(f);
    fopen(fnm2, "wb");

    // sorting
    int a = 0;
    for (int i = 0; i < n3a; i++) {
        if (arr->operator[](i)) {          // reading through the whole array and output
            //cout << i << endl; // only the elements containing something
            fwrite(&i, sizeof(int), 1, f);
            a++;               // making the outputted numbers be sorted
        }
    }
    fclose(f);
    // getting amount of memory occupied by the array
    cout << "mem=" << sizeof(arr) << " bytes " << a << /*" " << b <<*/ endl;
}

// gets amount of time function worked
void drt(void (*a)()) {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration;

    auto t1 = high_resolution_clock::now();
    a(); // <--
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> b = t2 - t1;
    printf("\n%g\n\n", b.count());
}

// launching functions
int main() {
    //task1b();
    //task1c();
    //task2ab<unsigned long long>(5);
    //task2c(64, 5);
    //task3a1();
    drt(&task3a);
}
