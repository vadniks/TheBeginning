/*
 ============================================================================
 Name        : Homework8.c
 Author      : Vad Nik
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "hoar.h"

void task1() {
	int arr[10] = {
			5, 3, 0, 1, 4, 8, 2, 9, 7, 6
	};

	int max = arr[0];

	int arr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for(int i = 0; i < 10; i++) {
		if(arr[i] > max)
			max = arr[i];
	}

	int min = max;

	for(int i = 10; i > 0; i--) {
		if(arr[i] < min)
			min = arr[i];
	}

	for(int i = min; i <= max; i++)
		arr2[i] = i;

	for(int i = 0; i < 10; i++) {
		//printf(" %d ", arr2[i]); // I don't know why, but if delete this cycle, sorted output will be with two units ('1' x2);
	}

	int arr3[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for(int i = 0; i <= 10; i++) {
		for(int j = min; j <= 10; j++) {
			if(arr[i] == arr2[j])
				arr3[i]++;
		}
	}

	int arr4[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for(int i = 0; i < 10; i++) {
		if(arr2[i] == arr4[i-1])
			continue;             // Don't know what to do with doubles.

		if(arr3[i] == 1)
			arr4[i] = arr2[i];

		if(arr3[i] == 2) {
			arr4[i] = arr2[i];
			arr4[i+1] = arr2[i];
		}
	}

	for(int i = 0; i < 10; i++)
		printf("Task 1: %d\n", arr4[i]);
}

int main(void) {

	task1();

	puts("");

	// Task 2:

	unsigned int arr[10] = {
			5, 3, 0, 1, 4, 8, 2, 9, 7, 6
	};

	hoar(arr, 10);

	for(int i = 0; i < 10; i++)
		printf("Task 2: %d\n", arr[i]);

	// End.

	return EXIT_SUCCESS;
}
