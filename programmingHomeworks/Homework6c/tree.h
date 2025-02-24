/*
 * tree.h
 *
 *      Author: Vad Nik.
 */

#ifndef TREE_H_
#define TREE_H_

#include <stdlib.h>
#include <stdio.h>

struct Tree {
	struct Tree * parent, * left, * right;
	unsigned int data;
};

struct Tree * treeCreate(const unsigned int data);
void treeDelete(struct Tree * tree);
void treePrint(struct Tree * tree);
/* Unsafe body, compilation warnings. */
void treeSearch(struct Tree * tree, const int value);
/* Might doesn't work properly, or at all. */
void treeAddAll(struct Tree * tree, const char * data);

#endif
