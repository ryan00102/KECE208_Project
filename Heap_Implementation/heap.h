/********************************************
	Class: Data Structure and Algorithms
	Project 2: Heap and Sort

	heap.h

	Name: ÃÖÁø¿ì	
	StudentID: 2019320011
	E-mail: ryan00102@naver.com

**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

typedef struct heap
{
	int *heapData;		//array pointer
	int size;
}heap, *HEAP;


//Given functions
HEAP createHeap();
void printHeap(HEAP h);
void swap(int*n1, int*n2);

//Heap common functions
void buildHeap(HEAP h, int* array, int arraySize);
void deleteHeap(HEAP h);
int findDepth(HEAP h);


//Heap operations
void insertNode(HEAP h, int value);
int dequeueHeap(HEAP h);
void heapSort(HEAP h, int *heapsort, int count);

//Heap functions(additional)
void makeHeap(int arr[], int i, int size);