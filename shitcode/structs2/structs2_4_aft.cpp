
// Variant 14

#pragma ide diagnostic ignored "modernize-use-nullptr"
#pragma ide diagnostic ignored "modernize-use-bool-literals"
#pragma ide diagnostic ignored "hicpp-exception-baseclass"

#include <cstdio>
#include "a.h"

typedef char* str;
typedef const char chr;
typedef chr* ctr;

// returns maximum value of the two provided ones
template<typename t>
constexpr t mx(t a, t b)
{ return a > b ? a : b; }

// tree node
struct nd final {
    int vl; // node value
    nd* lf; // left subtree vertex
    nd* rg; // right subtree vertex
    int hg; // height

    // constructor
    // initializing variables
    explicit nd(
        int vl,
        int hg = 1,
        nd* lf = 0,
        nd* rg = 0
    ) :
        vl(vl),
        lf(lf),
        rg(rg),
        hg(hg)
    {}

    // print node value
    void prt(bool a = 1/*add new line?*/) {
        printf("%d", vl);
        if (a) printf("\n");
    }
};

// node heigh or zero if it's null
int hg(nd* a/*node*/)
{ return a ? a->hg : 0; }

// balance factor
int bfc(nd* a/*node*/)
{ return a ? hg(a->rg) - hg(a->lf) : 0; }

// fix node height
void fhg(nd* a/*node*/)
{ a->hg = mx(hg(a->lf), hg(a->rg)) + 1; }

// rotate right
nd* rtrg(nd* a/*node*/) {
    // swap nodes
    nd* b = a->lf;
    a->lf = b->rg;
    b->rg = a;

    // fix their heights
    fhg(a);
    fhg(b);
    return b;
}

// rotate left
nd* rtlf(nd* a/*node*/) {
    // swap nodes
    nd* b = a->rg;
    a->rg = b->lf;
    b->lf = a;

    // fix their heights
    fhg(a);
    fhg(b);
    return b;
}

// balance node and its subnodes
nd* bln(nd* a/*node*/) {
    fhg(a); // fix node height
    if (bfc(a) == 2) { // if balance factor's greater then 1
        // if balance factor of the right vertex is negative
        if (bfc(a->rg) < 0)
            a->rg = rtrg(a->rg); // rotate right the right vertex
        return rtlf(a); // rotate leff the node
    }
    // if balance factor is less then -1
    if (bfc(a) == -2) {
        // if balance factor of the left vertex is positive
        if (bfc(a->lf) > 0)
            a->lf = rtlf(a->lf); // rotate left the left vertex
        return rtrg(a); // rotate right the node
    }
    return a;
}

// add node
void dd(int a/*node value*/, nd*& b/*root node*/) {
    if (!b) {
        b = new nd(a);
        return;
    }
    dd(a, b->vl > a ? b->lf : b->rg);
    b = bln(b);
}

// add nodes
template<typename... t>
void dd(
    nd*& d/*root node*/, 
    t... a/*node values (must be integers)*/
) {
    const int b = sizeof...(a); // size of the parameter list
    int c[b] = {a...}; // convert parameter list into array
    for (int i = 0; i < b; i++) // for each node value
        dd(c[i], d); // create and add each node
}

// print tree
void prt(nd* b/*root node*/, int c = 0/*recursion level*/) {
    if (!b) return; // if null

    if (b->lf) prt(b->lf, c + 1); // print left subtree

    // format output
    for (int i = 0; i < c; printf("    "), i++);
    b->prt(); // print each node value

    if (b->rg) prt(b->rg, c + 1); // print right subtree
}

// symmetric loop-through
void sprt(nd* a/*root node*/, bool b = 0/*is not root?*/) {
    if (!a) return; // if null
    sprt(a->lf, 1); // print left subtree

    a->prt(0); // print node value
    printf(" "); // add space

    sprt(a->rg, 1); // print right subtree

    if (!b) // if root
        printf("\n"); // add new line
}

// reverse loop-through
void rprt(nd* a/*root node*/, bool b = 0/*is not root?*/) {
    if (!a) return; // if null
    rprt(a->lf, 1); // print left subtree
    rprt(a->rg, 1); // print right subtree

    a->prt(0); // print node value
    printf(" "); // add space

    if (!b) // if root
        printf("\n"); // add new line
}

// sum of leafs
void lfsm(
    nd* a/*root node*/, 
    int* b = new int(),/*pointer to current sum*/
    bool c = 0,/*is end of elements reached?*/
    bool* d = new bool()/*pointer(is not the first element?)*/
) {
    if (!a) return; // if null

    lfsm(a->lf, b, 1, d); // search and sum in left subtree
    lfsm(a->rg, b, 1, d); // search and sum in right subtree

    // if node is leaf
    if (!a->lf and !a->rg) {
        // add plus sign if neccessary
        if (*d) printf(" + ");

        a->prt(0); // print node value
        *b += a->vl; // sum its value with sum of the previous ones

        *d = 1; // plus sign neccessarity flag is setting to true
    }

    if (!c) { // if all leafs found
        printf(" = %d\n", *b);
        delete b;
        delete d;
    }
}

// height of the tree
void hgh(
    nd* a,/*root node*/
    int* b = new int(),/*pointer(max height)*/
    bool c = 0/*is end reached?*/
) {
    if (!a) return; // if null

    hgh(a->lf, b, 1); // check left subtree
    hgh(a->rg, b, 1); // check right subtree

    // if this node's height is greater then max height
    if (a->hg > *b)
        *b = a->hg; // set max one to the node's one

//    *b += !a->lf and !a->rg ? 1 : 0;

    if (!c) { // if end reached
        printf("Height: %d\n", *b);
        delete b;
    }
}

// insert + balance, reverse loop-through, symmetric loop-through, sum of leafs, heigh of tree

void lnch() {
    nd* a = 0; // root node is null so far

    dd(a, 9, 4, 5, 6, 7, 1, 2, 0); // test node values
//    dd(a, 3, 2, 6, 1, 8, 4, 7, 5);
//    dd(a, 30, 20, 60, 10, 80, 40, 70, 50);
//    dd(a, 10, 20, 30, 40, 50, 25);

    prt(a); // print tree
    sprt(a); // symmetric print
    rprt(a); // reversed print
    lfsm(a); // leafes sum
    hgh(a); // tree height

    a = 0; // reset root node
    printf("\n");

    char b = 0; // buffer for input
    while (1) { // infinite cycle
        printf("Enter mode or q to exit: |%c|\n", b);
        if (scanf(" %c", &b) != 1) // read input
            throw 1; // aka assert

        if (b == 'a') {
            while (1) { // infinite cycle
                printf("Enter next digit or e to return: |%c|\n", b);
                b = 0; // reset buffer

                // read input
                if (scanf(" %c", &b) != 1)
                    throw 1; // assert

                if (b == 'e') break;
                dd(b - '0', a); // create and add new node
            }
        } else if (b == 's') {
            printf("Symmetric loop-through: ");
            sprt(a);
        } else if (b == 'r') {
            printf("Reversed loop-through: ");
            rprt(a);
        } else if (b == 'l') {
            printf("Sum of leafes: ");
            lfsm(a);
        } else if (b == 'h') {
            printf("Height of the tree: ");
            hgh(a);
        } else if (b == 't') {
            printf("Tree traversal:\n");
            prt(a);
        } else if (b == 'q') break;
    }
}
