/*
 * stack.c
 *
 *      Author: Vad Nik.
 */

#include <stdlib.h>
#include "stack.h"

struct SStack * newStack(const unsigned int num) {
	struct SStack * stack = (struct SStack *) malloc(sizeof(struct SStack));

	stack->p = (int *) malloc(sizeof(int) * num);
	stack->ind = -1;
	stack->maxNum = num;
	stack->size = 0;

	return stack;
}

void stackDelete(struct SStack * stack) {
	if(stack != NULL) {
		if(stack->p != NULL)
			free(stack->p);

		free(stack);
	}
}

void stackPush(struct SStack * stack, const int value) {
	if(stack->ind == stack->maxNum - 1)
		return;

	stack->ind++;
	stack->p[stack->ind] = value;
	stack->size++;
}

int stackPop(struct SStack * stack) {
	if(stack->ind >= 0) {
		stack->ind--;
		return stack->p[stack->ind + 1];
	}

	return -1;
}

int stackIsEmpty(struct SStack * stack) {
	return stack->size == 0;
}

int stackSize(struct SStack * stack) {
	return stack->size;
}

