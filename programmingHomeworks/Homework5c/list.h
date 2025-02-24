/*
 * list.h
 *
 *      Author: Vad Nik.
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
#include <stdlib.h>

struct Element {
	int value;
	struct Element * next;
};

struct Element * listNew(const int value);

void listDelete(struct Element * begin);

void listAdd(struct Element * begin, const int value);

void listPrint(struct Element * begin);

int listGet(struct Element * begin);

int listSize(struct Element * begin);

int listGetValue(struct Element * begin);

#endif
