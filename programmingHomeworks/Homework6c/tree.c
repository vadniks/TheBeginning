/*
 * tree.c
 *
 *      Author: Vad Nik.
 */

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

struct Tree * element;
int searchValue;

struct Tree * treeCreate(const unsigned int data) {
	struct Tree * tree = (struct Tree *) malloc(sizeof(struct Tree));

	if(tree == NULL) {
		fprintf(stderr, "Stack overflow");
		exit(-1);
	}

	tree->left = NULL;
	tree->right = NULL;
	tree->parent = NULL;
	tree->data = data;

	return tree;
}

void treeDelete(struct Tree * tree) {
	if(tree != NULL) {
		treeDelete(tree->left);
		treeDelete(tree->right);

		free(tree);
	}
}

void treePrint(struct Tree * tree) {
	if(tree != NULL) {
		printf("%u (", tree->data);

		treePrint(tree->left);

		printf(" , ");

		treePrint(tree->right);

		printf(" )");
	} else
		printf("NULL");
}

/* Might doesn't work properly or at all. */
void treeAddAll(struct Tree * tree, const char * data) {
	if(* data == '\0')
		return;

	if(* data != 'N' && * data != 'U' && * data != 'L' && * data != '(' && * data != ')' && * data != ',') {
		tree = treeCreate(* data);
		treeAddAll(tree->left, data+1);
		treeAddAll(tree->right, data+1);
	}

	if(* data == '(' || * data == ')') {
		if(* data == '(')
			treeAddAll(tree->left, data+1);
		else if(* data == ')' && * data+1 != ')')
			treeAddAll(tree->right, data+2);
	}

	if(* data == ',') {
		treeAddAll(tree->left, data+1);
		treeAddAll(tree->right, data+1);
	}

	treeAddAll(tree->left, data+1);
	treeAddAll(tree->right, data+1);
}

/* Internal function. */
/* Unsafe arguments, compilation warnings. */
void treeLrc(struct Tree * tree, void (* func)(struct Tree *)) {
	if(tree != NULL) {
		treeLrc(tree->left, func);
		treeLrc(tree->right, func);

		(* func)(tree);
	}
}

/* Internal function. */
void search(struct Tree * tree) {
	if(tree->data == searchValue && element == NULL)
		element = tree;
}

/* Unsafe body, compilation warnings. */
void treeSearch(struct Tree * tree, const int value) {
	if(tree != NULL) {
		searchValue = value;
		element = NULL;

		treeLrc(tree, &search);

		if(element != NULL)
			printf("Element %u with left child %u and right child %u\n", element->data, element->left->
					data, element->right->data);
	}
}
