/*
 ============================================================================
 Name        : Homework6.c
 Author      : Vad Nik
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int task1(char * value, int length) {
//	int result = 0;
//	for(int i = 0; i < length; value++, i++)   // Different solution.
//		result = (result * 131313) + * value + i;

	int result = 0x55555555;

	while (*value)
		result ^= * value++;

	return result; // I didn't understand what means xor ('^') of codes of symbols.
}

void task2_2() {
	struct Tree * tree = treeCreate(1);

	tree->left = treeCreate(2);
	tree->left->left = treeCreate(4);
	tree->left->right = treeCreate(5);

	tree->right = treeCreate(3);
	tree->right->left = treeCreate(6);
	tree->right->right = treeCreate(7);

	/*
	 *        1
	 *      /   \
	 *     2     3
	 *    / \   / \
	 *   4   5 6   7
	 *   -----------
	 */

	puts("\nTask 2:");

	treePrint(tree);

	puts("");

	treeSearch(tree, 3);

	treeDelete(tree);
}

void task2_3() {
	char str[256];
	int mode;
	printf("\nEnter file name: ");
	scanf("%s", str);
	printf("\nEnter bypass mode: ");
	scanf("%d", &mode);

	char out[256];

	FILE * file = fopen(str, "r");
	fgets(out, 256, file);
	fclose(file);

	treeAddAll(treeCreate(0), out);
}

int main(void) {

	printf("Task 1: %d\n", task1("long word", 9));

	task2_2();

	//task2_3(); // Not sure that it can works. See 'tree.c'.

	return EXIT_SUCCESS;
}
