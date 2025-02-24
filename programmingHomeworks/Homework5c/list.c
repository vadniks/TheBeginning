/*
 * list.c
 *
 *      Author: Vad Nik.
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Element * listNew(const int value) {
	struct Element * begin = (struct Element *) malloc(sizeof(struct Element *));

	if(begin == NULL) {
		perror("Stack overflow.");
		exit(1);
	}

	begin->value = value;
	begin->next = NULL;

	return begin;
}

void listDelete(struct Element * begin) {
	struct Element * current, * next = begin;

	while(next != NULL) {
		current = next;
		next = current->next;

		free(current);
	}
}

void listAdd(struct Element * begin, const int value) {
	struct Element * current = begin;

	while(current->next != NULL)
		current = current->next;

	current->next = listNew(value);
}

void listPrint(struct Element * begin) {
	struct Element * current = begin;

	while(current->next != NULL) {
		printf(" %d -> ", current->value);

		current = current->next;
	}

	puts("");
}

int listGet(struct Element * begin) {
	struct Element * current = begin;
	int value = 0;

	if(current->next != NULL) {
		value = current->value;
		current = current->next;
	}

	return value;
}

int listSize(struct Element * begin) {
	struct Element * current = begin;

	int count = 0;

	while(current->next != NULL) {
		count++;
		current = current->next;
	}

	return count;
}

int listGetValue(struct Element * begin) {
	return begin->value;
}
