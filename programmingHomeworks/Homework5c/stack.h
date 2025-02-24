/*
 * stack
 *
 *      Author: Vad Nik.
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdlib.h>

struct SStack {
	int * p;
	int ind;
	unsigned int maxNum;
	unsigned int size;
};

struct SStack * newStack(const unsigned int num);

void stackDelete(struct SStack * stack);

void stackPush(struct SStack * stack, const int value);

int stackPop(struct SStack * stack);

int stackIsEmpty(struct SStack * stack);

int stackSize(struct SStack * stack);

#endif
