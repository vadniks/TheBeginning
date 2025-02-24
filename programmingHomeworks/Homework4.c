/*
 * File:   main.c
 * Author: Vad Nik
 */

#include <stdio.h>
#include <stdlib.h>

int arr[4][4] = {
		{0, 0, 0, 0},
		{1, 0, 1, 0},
		{1, 0, 1, 0},
		{1, 1, 1, 2}
};

int task1(int x, int y) {

	if (y == 3 && x == 2)
			task1(3, 3);

	if (x == 3 && y == 3)
		return 0;

	if (arr[x][y] == 0) {
		arr[x][y] = 3;
		task1(x, y+1);
	}

	if (y == 3 && arr[x+1][y] == 0)
		task1(x+1, y);

	if (arr[x+1][y] == 0)
		task1(x+1, y);

	if (arr[x+1][y] == 2) {
		arr[x+1][y] = 3;
		return 1;
	}

	if (arr[x][y+1] == 2) {
		arr[x][y+1] = 3;
		return 1;
	}

	if (x == 2 && y == 3) {
		task1(x+1, y);
		task1(x+1, y-1);
		task1(x+1, y-2);
	}

	return 0;
}

unsigned int task2(char * str, char * str2) {

    if (* str == '\0' || * str2 == '\0')
        return 0;

    if (* str == * str2)
        return 1 + task2(str + 1, str2 + 1);

    return (task2(str + 1, str2) > task2(str, str2 + 1)) ? task2(str + 1, str2) : task2(str, str2 + 1);
    // Couldn't found 'max()' function.
}

int main(int argc, char** argv) {
    printf("Task 2: %u \n", task2("aacd", "abaacd"));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
        	printf(" %d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");

    task1(0, 0); // 1 - closed, 0 - free, 2 - destination.

    for (int i = 0; i < 4; i++) {
    	for (int j = 0; j < 4; j++)
    		printf(" %d ", arr[i][j]);
    	printf("\n");
    }
    printf("\n");

    return (EXIT_SUCCESS);
}
