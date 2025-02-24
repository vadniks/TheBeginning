
// variant 21

#include <iostream>
#include <cstring>
#include "a.h"

using namespace std;

typedef unsigned long unt;
typedef const char* ctr;

// element
struct bk {
    ctr nb; // number
    ctr dr; // address

    // constructor initializing properties
    bk(ctr nb, ctr dr) :
        nb(nb), dr(dr)
    {}

    // just amkes a copy of this object
    bk* cpy() {
        char* a = new char[strlen(dr)];
        char* b = new char[strlen(nb)];

        strcpy(a, dr);
        strcpy(b, nb);

        return new bk(b, a);
    }
};

// element wrapper
struct el {
    bk* kb = 0; // element
    unt sz = 0; // how many elements are contained
    // in one cell with the same hash

    // constructor initializing properties
    el(struct bk *bk, unt sz) : kb(bk), sz(sz) {}

    // destructor deleting book
    ~el() 
    { delete kb; }
};

class hstbl {
public:
    const unt kk = 1; // hashing multiplier
    el** tbl; // array of the element wrapers
    unt sz = 0; // number of elements inserted
    unt ln; // array length

    // constructor initialising variables
    explicit hstbl(unt ln = 2) :
        ln(ln), tbl(new el*[ln])
    {}

    // destructor deletes array
    ~hstbl() 
    { delete[] tbl; }

    // rebuild and rehash the table
    void rbl() {
        cout << "rehashing: " << endl;

        unt nln = ln * 2; // increment the length
        auto* tt = new hstbl(nln); // create new temporary hash table
        el* e = 0; // define the buffer

        // loop through the whole array
        for (unt i = 0; i < ln; i++) {
            e = tbl[i]; // take each element

            // check it's not null and not empty
            if (!e or !e->kb)
                continue;

            cout << "Inserting to temp" << endl;
            tt->ns(e->kb->cpy()); // and if it is copy it
                                  // to the temporary array
        }
        delete[] tbl; // delete the original array
        tbl = new el*[nln]; // create a new one with larger capacity
        sz = 0; // set it's size to 0
        ln = nln; // set it's length to the incremented one

        // loop through the temporary array
        for (unt i = 0; i < nln; i++) {
            e = tt->tbl[i]; // pick each element

            if (!e or !e->kb) // null check
                continue;

            cout << "Inserting to this" << endl;
            this->ns(e->kb->cpy()); // copy the temporary's element into
                                    // the growed original array
        }
        delete tt; // delete temporary array

        cout << "end rehashing\n" << endl;
    }

    // insert an element
    void ns(bk* a) {
        unt b = hs(a); // hash
        cout << "Adress: " << a->dr << " Hash: " << b << endl;
        // outputting the book's author and hash

        bool gr = 0;

        if (b >= ln) { // if the hash is greater than the array's length
            ln = b + 1; // then grow the array
            tbl = (el**) realloc(tbl, sizeof(el*) * ln);
            gr = 1;
        }

        // if the hash indexed array cell is null then
        // the new book wrapper is getting allocated in there
        if (!tbl[b])
            tbl[b] = new el(0, 0);

        // if the hash indexed array cell isn't empty
        if (tbl[b]->kb) {
            // looping through the array
            for (unt i = 0, c = 0;; i++) {
                c = ndx(b, i, a->nb); // new index for the book
                cout << "| " << i << ' ' << c << endl;
                // outputting steps and the generted indexes

                if (c >= ln) { // if the hash is greater than the array's length
                    ln = c + 1; // then grow the array
                    tbl = (el**) realloc(tbl, sizeof(el*) * ln);
                    gr = 1;
                }

                // if the regular cell is null then allocate new one
                if (!tbl[c])
                    tbl[c] = new el(0, 0);

                // if the regular cell is empty
                if (!tbl[c]->kb) {
                    // then assign the book to this cell
                    tbl[c]->kb = a;

                    // increment the number of books contained
                    // in the same cell
                    tbl[b]->sz++;
                    sz++; // increment the total number of books
                    break; // end looping
                }
            }
        } else { // if the hash indexed array cell is empty
            tbl[b]->kb = a; // then assign the book to this cell
            sz++; // increment the total number of books
        }
        cout << endl;

        // check the load factor and the fact of array growing
        if ((float) sz / (float) ln >= 0.7 or gr)
            rbl(); // if any of them is true rebuild and rehash the table
    }

    // delete
    void dl(ctr a /* number */) {
        unt c = hs(a); // hash
        if (c >= ln)
            return;

        el* b = tbl[c]; // get the hash indexed array cell

        // if the cell isn't empty and the isbn of it's book
        // equals to the parameter
        if (b and b->kb and !strcmp(b->kb->nb, a)) {
            delete b->kb; // then delete that book
            tbl[c]->kb = 0; // make the cell be empty
            sz--; // decrement the number of total books
        } else { // otherwise
            // loop through the array until the right book will be found
            for (unt i = 1, d = 0; i < ln; i++) {
                d = ndx(c, i, a); // generate new index
                if (d >= ln) // if new index is greater than the array's length
                    break; // then end looping

                b = tbl[d]; // get a cell indexed with that index
                if (!b) // if the next cell is empty then the end of
                    break; // items with one hash was reached so end lopping

                // if the cell isn't empty and it's book's isbn
                // equals the parameter
                if (b->kb and !strcmp(b->kb->nb, a)) {
                    delete b->kb; // then delete that book
                    tbl[d]->kb = 0; // make the cell be empty

                    tbl[c]->sz--; // decrement the number of books contained
                    // in the same cell
                    sz--; // decrement the total number of books
                    break; // end looping
                }
            }
        }
    }

    // hash an element
    unt hs(bk* a)
    { return hs(a->nb); } // delegate to 'hash a number'

    // hash a number
    unt hs(ctr a)
    { return atoi(a) % ln; }

    // generate next index
    unt ndx(unt hs, unt i, ctr a)
    { return hs + i * (1 + atoi(a) % (ln + 1)); }

    // get an 'a' number'ed book
    bk* gt(ctr a) {
        unt b = hs(a); // hash
        if (b >= ln) // if the hash is greater than the array's length
            return 0; // then end lopping

        el* c = tbl[b]; // hash indexed cell

        // if the cell isn't empty and it's book's isbn
        // equals to the parameter
        if (c and c->kb and !strcmp(c->kb->nb, a))
            return c->kb; // then it the book contained
            // within is the right one
        else { // otherwise
            // loop through the array
            for (unt i = 1, d = 0; i < ln; i++) {
                d = ndx(b, i, a); // next generated index
                if (d >= ln)
                    break;

                c = tbl[d]; // cell indexed with it
                if (!c) // if the cell is empty
                    break; // then end lopping

                // if the cell isn't empty and it's book's isbn
                // equals to the parameter
                if (c->kb and !strcmp(c->kb->nb, a))
                    return c->kb; // it's the right one so return it's book
            }
        }
        // if reached here then nothing was found so return null
        return 0;
    }

    // print all books
    void prt() {
        el* a = 0; // buffer for a regular cell
        unt b = 0, c = 0; // buffers for hash and next index
        bk* d = 0; // buffer for book
        bool* e = (bool*) calloc(ln, sizeof(bool)); // array with already printed books

        // loop through the array
        for (int i = 0; i < ln; i++) {
            a = tbl[i]; // get regular cell
            if (!a or !a->kb) // if it is null or is empty
                continue; // then skip this cell

            b = hs(a->kb); // get the cell's book's hash
            if (b >= ln) // if the hash is greater than the array's length
                break; // then end lopping

            if (a->sz > 0) { // if the cell contains more than 1 book
                if (!e[i]) { // if it wasn't printed
                    cout <<
                         a->kb->nb << ' ' <<
                         a->kb->dr << endl;
                    e[i] = 1;
                }

                // loop until next index will point to a null cell
                for (int j = 0;; j++) {
                    c = ndx(b, j, a->kb->nb); // generate next index
                    if (c >= ln) // if the hash is greater than the array's length
                        break; // then end lopping

                    a = tbl[c]; // replace the old cell with
                    // the next regular cell
                    if (!a) // if it is null
                        break; // then end the secondary looping

                    d = a->kb; // otherwise get it's book
                    // if the book isn't null and it wasn't printed
                    if (d and !e[c]) {
                        cout <<
                            a->kb->nb << ' ' <<
                            a->kb->dr << endl;
                        e[c] = 1; // and mark it's index as printed
                    }
                }
            } else { // if the cell contains only one book
                if (!e[i]) { // if it wasn't printed
                    cout <<
                         a->kb->nb << ' ' <<
                         a->kb->dr << endl;
                    e[i] = 1; // and mark it's index as printed
                }
                // then print it
            }
        }
        free(e); // free the memory allocated for temporary bool array
    }
};

// program's entry point
void lnch() {
    auto tbl = hstbl(); // create an object of the class
    // insert test elements
    tbl.ns(new bk("1111111111", "Address0"));
    tbl.ns(new bk("9121101856", "Address1"));
    tbl.ns(new bk("2115678111", "Address2"));
    tbl.ns(new bk("4151161111", "Address3"));
    tbl.ns(new bk("8160000051", "Address4"));
    tbl.ns(new bk("8888888888", "Address5"));
    tbl.ns(new bk("1111111119", "Address6"));
    tbl.ns(new bk("5432123451", "Address7"));
    tbl.ns(new bk("1000000000", "Address8"));
    tbl.ns(new bk("9999999999", "Address9"));
    tbl.ns(new bk("9876543210", "Address10"));

    // print them
    cout << "\nPrinting\n";
    tbl.prt();

    // search 'n print each element
    cout << endl;
    cout << tbl.gt("1111111111")->dr << endl;
    cout << tbl.gt("9121101856")->dr << endl; //
    cout << tbl.gt("2115678111")->dr << endl;
    cout << tbl.gt("4151161111")->dr << endl;
    cout << tbl.gt("8160000051")->dr << endl; //
    cout << tbl.gt("8888888888")->dr << endl; //
    cout << tbl.gt("1111111119")->dr << endl;
    cout << tbl.gt("5432123451")->dr << endl; //
    cout << tbl.gt("1000000000")->dr << endl;
    cout << tbl.gt("9999999999")->dr << endl; //
    cout << tbl.gt("9876543210")->dr << endl;

    // delete some elements
    tbl.dl("9121101856");
    tbl.dl("8160000051");
    tbl.dl("8888888888");
    tbl.dl("5432123451");
    tbl.dl("9999999999");

    // print the rest
    cout << "\nPrinting\n";
    tbl.prt();

    // insert a new element
    tbl.ns(new bk("5555555555", "Address_"));
    cout << endl;
    tbl.prt(); // and print all elements
    
    int c = -1;
    char* a = new char[16];
    char* b = new char[10];

    while (1) {
        cout << "Enter command: mode phone address\n";
        cin >> c;

        if (c == 0) {
            cout << "Enter number\n";
            cin >> a;
            cout << "Enter address\n";
            cin >> b;
            tbl.ns(new bk(a, b));
        } else if (c == 1) {
            cout << "Enter number\n";
            cin >> a;
            tbl.gt(a);
        } else if (c == 2) {
            cout << "Enter number\n";
            cin >> a;
            tbl.dl(a);
        } else if (c == 3)
            tbl.prt();
        else
            break;
    }
}
