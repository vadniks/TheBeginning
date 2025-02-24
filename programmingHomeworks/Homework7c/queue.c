/*
 * queue.c
 *
 *      Author: Vad Nik.
 */

#include <stdlib.h>
#include "queue.h"

struct Queue * newQueue(const unsigned int num) {
	struct Queue * queue = (struct Queue *) malloc(sizeof(struct Queue));

	queue->p = (int *) malloc(sizeof(int) * num);
	queue->push = 0;
	queue->pop = 0;
	queue->maxNum = num;
	queue->size = 0;

	return queue;
}

void queueDelete(struct Queue * queue) {
	if(queue != NULL) {
		if(queue->p != NULL)
			free(queue->p);

		free(queue);
	}
}

void queuePush(struct Queue * queue, const int value) {
	if(queue->push == queue->maxNum) {
		unsigned int current, v;

		for(current = queue->pop, v = 0; current < queue->push; current++, v++)
			queue->p[v] = queue->p[current];

		queue->pop = 0;
		queue->push -= queue->pop;
	}

	if(queue->push < queue->maxNum) {
		queue->p[queue->push] = value;
		queue->push++;
		queue->size++;
	}
}

int queuePop(struct Queue * queue) {
	if(queue->pop < queue->push) {
		queue->pop++;
		return queue->p[queue->pop - 1];
	}

	return 0;
}

int isQueueEmpty(struct Queue * queue) {
	return queue->size == 0;
}
