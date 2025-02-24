/*
 ============================================================================
 Name        : Homework5.c
 Author      : Vad Nik

 Please see all my comments in main() function/method (I don't fully know how to call its in C).
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "list.h"
#include "queue.h"

int task1(int num, struct SStack * stack1) {
	stackPush(stack1, num % 2);
	if (num == 0) return 0;
	else
		return task1(num / 2, stack1)*10 + num % 2;
}

void task2() {
	struct Element * element = listNew(100000);

	for(int i = 0; i < 1000000000000000; i++) {
		listAdd(element, 1);
		printf(" %d\n", i);
	}

	/*
	 * I've been waiting for over 10 minutes, but nothing haven't been happened,
	 * and if honestly, I'm afraid for my computer.
	 * But I thing, I did task 2 (it should be works like in task 2 description)
	 * (I found that if malloc() function returns NULL there's stack overflow,
	 * fix me if I'm wrong).
	 */

	listDelete(element);
}

// Task 3 begin:
char getLeftPair(char brace) {
    if (brace == ')') return '(';
    else if (brace == '}') return '{';
    else if (brace == ']') return '[';
    else return brace;
}

int task3(char * string) {

	/*
	 * Commented calls to printf() function are for debug.
	 */

	int count = 0;
	while(string[count] != '\n')
		count++;

	//printf(" %d ", count);

	struct SStack * stack = newStack(count);
	struct SStack * stack2 = newStack(count);
	int isGood = 1;
	int i = 0;

	while(* string != '\0') {
		if(string[i] == '\0')
			break;

		if(string[i] == '(' || string[i] == '{' || string[i] == '[')
			stackPush(stack, string[i]);
		else if(string[i] == ')' || string[i] == '}' || string[i] == ']') {
			stackPush(stack2, string[i]);
			if(stackIsEmpty(stack)) {
				isGood = 0;
				break;
			}

			char pairC = stackPop(stack);

			//printf(" %c ", pairC);

			if(getLeftPair(string[i]) != (char) pairC) {
				isGood = 0;
				break;
			}
		}
		i++;
	}

	//printf(" st %d %d %d %d ", isGood, stackIsEmpty(stack), stackSize(stack), stackSize(stack2));

	if(isGood && stackIsEmpty(stack))
		isGood = 0;

	if(isGood && stackIsEmpty(stack2))
		isGood = 0;

	if(stackSize(stack) > stackSize(stack2))
		isGood = 0;

	if(stackSize(stack2) > stackSize(stack))
		isGood = 0;

	stackDelete(stack);
	stackDelete(stack2);

	return isGood;
}
// end.

// Task 4 begin:
struct Element * task4(struct Element * src) {
	struct Element * begin = listNew(listGetValue(src));

	for(int i = 0; i < listSize(src); i++)
		listAdd(begin, listGet(src));

	return begin;
}

int checkTask4(struct Element * src, struct Element * out) {
	if(listGetValue(src) != listGetValue(out))
		return 0;

	if(listSize(src) != listSize(out))
		return 0;

	for(int i = 0; i < listSize(src); i++) {
		if(listGet(src) != listGet(out))
			return 0;
	}

	return 1;
}
// end.

void task6() {
	const int LENGTH = 3;
	struct Queue * queue = newQueue(LENGTH);

	for(int i = 0; i < LENGTH; i++)
		queuePush(queue, i);

	for(int i = 0; i < LENGTH; i++)
		printf("Task 6: %d\n", queuePop(queue));

	queueDelete(queue);
}

int main(int argc, char** argv) {

	/*
	 * I work in Eclipse and it's autocomplete/file template function makes this:
	 * Eclipse wrote 'STACK_H_' instead of 'STACK_H'.
	 * I don't know difference between these '_' symbols,
	 * so just keep it in mind if anything won't work properly.
	 *
	 * See all the '*.h' and '*.c' files.
	 */

	// Task 1:
	struct SStack * stack1 = newStack(100);

	task1(51, stack1);

	stackPop(stack1);
	for(int i = 0; i < 8; i++)
		printf("Task 1: %d\n", stackPop(stack1));
	// -1 ~= (like) null. 1 \n 1 \n 0 \n 0 \n 1 \n 1 \n -1 \n -1 - it's 110011 or 00110011.
	// Only 8 binary length.

	stackDelete(stack1);
	// end.

	puts("Please uncomment task 2 method/function call. See source in 'list.c'.");

	//task2();

	printf("Task 3: %s\n", task3("({}){}\n") ? "good" : "bad");
	// Only braces and '\n' symbol, it must be in the end. 1 - all right, 0 - not.

	// Task 4:
	struct Element * testIn = listNew(1);
	listAdd(testIn, 2);
	listAdd(testIn, 3);

	struct Element * testOut = task4(testIn);

	printf("Task 4: %s\n", checkTask4(testIn, testOut) ? "successful" : "unsuccessful");
	// end.

	task6();

	return EXIT_SUCCESS;
}
