/* 
 * File:   HW3.c
 * Author: Vad Nik
 */

#include <stdio.h>
#include <stdlib.h>

#define ARR_LENGTH 10

void task1() {
    int arr[ARR_LENGTH] = {3, 1, 5, 6, 0, 4, 7, 9, 2, 8};
    int count = 0;

    for (int i = 0; i < ARR_LENGTH; i++) {
        for (int j = 0; j < ARR_LENGTH; ++j) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
            }
        }
    }

    for (int k = 0; k < ARR_LENGTH; ++k)
        printf("Task 1: %d\n", arr[k]);
    printf("Task 1: count: %d\n", count);
}

void task2() {
    // Specialy reversed.
    
    int arr[ARR_LENGTH] = {3, 1, 5, 6, 0, 4, 7, 9, 2, 8};
    
    for (int i = 0; i < ARR_LENGTH/2; i++) {
        int swapped = 0;
        for (int j = i; j < ARR_LENGTH - i - 1; j++) {
            if (arr[j] < arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        
        for (int j = ARR_LENGTH - 2 - i; j > i; j--) {
            if (arr[j] > arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                swapped = 1;
            }
        }
        
        if(!swapped)
            break;
    }
    
    for (int k = 0; k < ARR_LENGTH; ++k)
        printf("Task 2: %d\n", arr[k]);
}

int arr2[ARR_LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
#define ELEMENT 9

int task3() {
   int l1, i, j, flag = 0;
   l1 = 0;
   i = ARR_LENGTH - 1;
   int element = 0;
   
   while (l1 < i) {
       j = (l1 + i);
       if (arr2[j] == ELEMENT) {
           //printf("Task 3: the element %d in %d", ELEMENT, j);
           element = j;
           flag = 1;
           break;
       } else {
           if (arr2[j] < ELEMENT) {
               l1 = j + 1;
           } else {
               i = j - 1;
           }
       }
   }
   
   if (flag == 0)
       return -1;
       //printf("Task 3: there aren't current element in the array.");
   
   return element;
}

int main(int argc, char** argv) {

    task1();
    task2();
    printf("Task 3: %d\n", task3());
    
    return (EXIT_SUCCESS);
}