/*
 * hoar.c
 *
 *      Author: Vad Nik.
 */

#include "hoar.h"
#include <stdlib.h>
#include <string.h>

void hoar(unsigned int * arr, const unsigned int size) {
	if(size == 0 || size == 1)
		return;

	unsigned int * left, * right;

	left = (unsigned int *) malloc(sizeof(unsigned int) * size);
	right = (unsigned int *) malloc(sizeof(unsigned int) * size);

	const unsigned int middle = size / 2;
	const unsigned int middleVal = arr[middle];
	unsigned int v, sizeLeft, sizeRight;

	for(v = 0, sizeLeft = 0, sizeRight = 0; v < size; v++) {
		if(v != middle) {
			if(arr[v] < middleVal) {
				left[sizeLeft] = arr[v];
				sizeLeft++;
			} else {
				right[sizeRight] = arr[v];
				sizeRight++;
			}
		}
	}

	hoar(left, sizeLeft);
	hoar(right, sizeRight);

	memcpy(arr, left, sizeof(unsigned int) * sizeLeft);
	arr[sizeLeft] = middleVal;
	memcpy(arr + sizeLeft + 1, right, sizeof(unsigned int) * sizeRight);

	free(left);
	free(right);
}
