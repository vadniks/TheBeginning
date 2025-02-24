/*
 ============================================================================
 Name        : Homework7.c
 Author      : Vad Nik
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

#define MTX(row, col) (mtx + row * 6 + col)

void task1() {
	char out[256];
	char out2[256];
	FILE * file = fopen("task1.txt", "r");

	const unsigned int NUM = (char) fgets(out2, 256, file)[0] - '0';

	bool * mtx = (bool *) malloc(sizeof(bool) * NUM * NUM);
	bool * isEnter = (bool *) malloc(sizeof(bool) * NUM);

	unsigned int v;

	for(v = 0; v < NUM; v++)
		mtx[v] = false;

	for(v = 0; v < NUM; v++)
		isEnter[v] = false;

	fseek(file, 1, SEEK_SET);
	printf("Task 1: peaks: %d\n", NUM);

	int arr[NUM][NUM]; // I didn't understand how does macros (MTX(row, col)) work. 1 - true, 0 - false.

	for(int i = 0; i < NUM+1; i++) {
		char * out3 = fgets(out+i, 256, file);
		//printf("Task 1: %s", out3);

		if(i > 0) {
			for(int j = 1; j <= NUM; j++)
				arr[i-1][j-1] = out3[j] - '0';
		}
	}

	puts("Task 1:");
	for(int i = 0; i < NUM; i++) {
		for(int j = 0; j < NUM; j++) {
			printf(" %d ", arr[i][j]);
		}
		puts("");
	}

	free(mtx);
	free(isEnter);

	fclose(file);
	puts("");
}

void task2(int node) {
	int mtx[7][7] = {
		//   1  2  3  4  5  6  7
	/*1*/   {0, 1, 0, 0, 0, 0, 0},
	/*2*/	{1, 0, 1, 0, 0, 0, 0},
	/*3*/	{0, 1, 0, 1, 0, 0, 0},
	/*4*/	{0, 0, 1, 0, 1, 0, 0},
	/*5*/	{0, 0, 0, 1, 0, 1, 0},
	/*6*/	{0, 0, 0, 0, 1, 0, 1},
	/*7*/	{0, 0, 0, 0, 0, 1, 0}
	};

	int vis[7];
	int count = 0;
	int head = 0;

	for(int i = 0; i <= 7; i++)
		vis[i] = 0;

	struct Queue * queue = newQueue(1);

	queuePush(queue, node);
	vis[node] = 1;

	while(head < count) {
		node = queuePop(queue);
		printf("Task 2: %d\n", node+1);

		for(int i = 0; i <= 7; i++) {
			if(mtx[node][i] && !vis[i]) {
				queuePush(queue, i);
				vis[i] = 1;
			}
		}
	}

	queueDelete(queue);
}

bool dfs(bool * mtx, bool * isEnter, const unsigned int ind, const unsigned int findInd) {
	unsigned v;

	if(ind == findInd) {
		printf("%u ", ind + 1);

		return true;
	}

	if(isEnter[ind])
		return false;

	isEnter[ind] = true;

	for(v = 0; v < 6; v++) {
		if(* MTX(ind, v) && dfs(mtx, isEnter, v, findInd)) {
			printf("%u ", ind + 1);
			return true;
		}
	}

	isEnter[ind] = false;

	return false;
}

int main(int argc, char** argv) {

	task1();

	task2(1);

	unsigned int v;
	bool * mtx, * isEnter;

	mtx = (bool *) malloc(sizeof(bool) * 6 * 6);
	isEnter = (bool *) malloc(sizeof(bool) * 6);

	for(v = 0; v < 6; v++)
		mtx[v] = false;

	for(v = 0; v < 6; v++)
		isEnter[v] = false;

	* MTX(0, 1) = * MTX(1, 0) = true;
	* MTX(0, 4) = * MTX(4, 0) = true;

	* MTX(1, 2) = * MTX(2, 1) = true;
	* MTX(1, 5) = * MTX(5, 1) = true;

	* MTX(2, 3) = * MTX(3, 2) = true;
	* MTX(2, 5) = * MTX(5, 2) = true;

	* MTX(4, 5) = * MTX(5, 4) = true;

	dfs(mtx, isEnter, 0, 5);

	printf("\n");

	free(mtx);
	free(isEnter);

	return EXIT_SUCCESS;
}
