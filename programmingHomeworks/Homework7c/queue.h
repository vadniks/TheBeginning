/*
 * queue.h
 *
 *  Created on: 21 апр. 2018 г.
 *      Author:
 */

#ifndef QUEUE_H_
#define QUEUE_H_

struct Queue {
	int * p;
	int push, pop;
	unsigned int maxNum;
	unsigned int size;
};

struct Queue * newQueue(const unsigned int num);

void queueDelete(struct Queue * queue);

void queuePush(struct Queue * queue, const int value);

int queuePop(struct Queue * queue);

int isQueueEmpty(struct Queue * queue);

#endif
