/********************************************
	Class: Data Structure and Algorithms
	Project 2: Heap and Sort

	heap.c

	Name: ÃÖÁø¿ì	
	StudentID: 2019320011
	E-mail: ryan00102@naver.com

**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "heap.h"

/*
	@Function name: HEAP createHeap()
	@Parameters: No parameter
	@Returns: return newly created heap
	@Descriptions: 
	1) Allocate address for new heap.
	2) Initialize ADT values of HEAP (heapData has 100 * 4 bytes as arraysize.
	@Error cases: There is no error case.
*/
HEAP createHeap()
{
	HEAP h = (HEAP)malloc(sizeof(heap));
	h->size = 0;
	h->heapData = (int*)malloc(sizeof(int)*100);
	return h;
}

/*
	@Function name: void makeHeap(int arr[], int i, int size)
	@Parameters:
	1) int arr[] : integer array that should be maintained to have heap properties
	2) int i : index of parent node that can be swapped with a child to maintain heap property of the array
	3) int size : size of arr[](first parameter)
	@Returns: No return
	@Descriptions: 
	1) Allocate index number for children of arr[i].
	2) Find largest value of the arr[i] and its children
	3) Swap the largest value with arr[i] if arr[i] is not the largest value.
	4) Call this function for the arr[largest] to maintain heap property if arr[i] was not the largest value.
	@Error cases: There is no error case.
*/	
void makeHeap(int arr[], int i, int size)
{
	
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if (l < size) {
		if (arr[l] > arr[largest])
		{
			largest = l;
		}
	}
	if (r < size) {
		if (arr[r] > arr[largest])
		{
			largest = r;
		}
	}
	if (largest != i) {
		swap(&arr[i], &arr[largest]);

		makeHeap(arr, largest, size);
	}
}

/*
	@Function name: void buildHeap(HEAP h, int* array, int arraySize)
	@Parameters:
	1) HEAP h : Heap that would contain values of array in heap order
	2) int* array : array that has value going to be inserted in the HEAP
	3) int arraySize : size of array(parameter)
	@Returns: No return
	@Descriptions:
	1) Using makeHeap function, make array that has value going to be inserted have heap property.
	2) Insert value of array to heap's array pointer, increasing size of heap's array.
	@Error cases:
	1) If there is no heap then print error message.
*/
void buildHeap(HEAP h, int* array, int arraySize)
{
	for (int i = floor(arraySize / 2) - 1; i >= 0; i--) {
		makeHeap(array, i, arraySize);
	}

	for (int i = 0; i < arraySize; i++) {
		h->heapData[i] = array[i];
		h->size++;
	}
	
	if (h->size == 0 || h == NULL) {
		printf("Error : No heap exists");
	}
	
}

/*
	@Function name: deleteHeap(HEAP h)
	@Parameters:
	1) HEAP h : heap going to be deleted
	@Returns: No return
	@Descriptions: 
	1) free pointer value of h and free h.
	@Error cases:
	1) If there is no heap, then print error message.
*/
void deleteHeap(HEAP h)
{
	
	if (h == NULL) {
		printf("Error: No heap exists");
		return;
	}
	else {
		free(h->heapData);
		free(h);
		printf("Successfully deleted");
	}
}


/*
	@Function name: int findDepth(HEAP h)
	@Parameters: 
	1) HEAP h : the heap whose array's depth should be printed.
	@Returns: depth of HEAP h
	@Descriptions:
	1) Calculate depth of HEAP h with logarithm operartion.
	2) Return the depth.
	@Error cases: 
	1) If there is no heap, then print error message
*/
int findDepth(HEAP h)
{
	
	if (h == NULL) {
		printf("Error: No heap exists.");
		return 0;
	}
	else {
		int depth = ceil(log(h->size) / log(2));
		return depth;
	}
}


/*
	@Function name: void insertNode(HEAP h, int value)
	@Parameters: 
	1) HEAP h : the heap that contains heap array that a new node is going to be inserted
	2) int value : new integer value going to be inserted in the heap array.
	@Returns: There is no return value.
	@Descriptions: 
	1) Increase a size of the heap by one.
	2) Insert the new node in the end of the heap array.
	3) After inserting the node, maintain the heap property using makeHeap function.
	@Error cases:
	1) If there is no heap to insert a new node, then print error message.
*/
void insertNode(HEAP h, int value)
{
	if (h == NULL) {
		printf("Error: No heap exists.");
		return;
	}
	else {
		h->size++;
		h->heapData[h->size - 1] = value;
		for (int i = floor(h->size / 2) - 1; i >= 0; i--) {
			makeHeap(h->heapData, i, h->size);
		}
	}
}


/*
	@Function name: int dequeueHeap(HEAP h)
	@Parameters: 
	1) HEAP h : the heap whose heap array will dequeue first value of the array.
	@Returns: return a value that a root of the heap contains (first element in the heap array).
	@Descriptions: 
	1) Put the first node of the heap array in the integer value 'outnode'
	2) Move elements of the heap array in the forward manner by one index.
	3) Decrease the size of the heap array by one.
	4) After moving the nodes, maintain the heap property using makeHeap function.
	5) return the intger value outnode, original first value of the heap array.
	@Error cases:
	1) If there is no heap, then print error message.
*/
int dequeueHeap(HEAP h)
{
	if (h == NULL || h->size == 0) {
		printf("Error: No heap exists.");
		return 0;
	}
	else {
		int outnode = h->heapData[0];
		for (int i = 0; i < h->size; i++) {
			h->heapData[i] = h->heapData[i + 1];
		}
		h->size--;
		for (int i = floor(h->size / 2) - 1; i >= 0; i--) {
			makeHeap(h->heapData, i, h->size);
		}
		return outnode;
	}
}


/*
	@Function name: void heapSort(HEAP h, int *heapsort, int count)
	@Parameters: 
	1) HEAP h : the heap that will contain sorted array by this function
	2) int *heapsort : the array pointer containing unsorted values
	3) int count : the number of elements of the array pointer.
	@Returns: No return value.
	@Descriptions: 
	1) The heapsort(array pointer)'s values are assigned into the heap array of HEAP h in the heap property, using buildHeap function.
	2) Swap the first element and the last element one by one to make a sorted list.
	3) Maintaing the heap property in the array except for new last element. 
	4) This means that the original first element is removed from the heap array.
	5) Repeating this swapping operation for the new first element. 
	6) Finally, print the sorted list in ascending order.
	@Error cases: There is no error case.
*/
void heapSort(HEAP h, int *heapsort, int count)
{
	buildHeap(h, heapsort, count);
	
	for (int i = h->size - 1; i >= 1; i--) { /*ascending*/
		for (int j = floor(count / 2) - 1; j >= 0; j--) {
			makeHeap(h->heapData, j, count);
		}
		swap(&h->heapData[i], &h->heapData[0]);
		count--;
	}
	printf("Sorted list : ");
	for (int i = 0; i < h->size - 1; i++) {
		printf("%d ", h->heapData[i]);
	}
}


/*
	@Function name: void swap(int*n1, int*n2)
	@Parameters: int*n1, int*n2
	@Returns: No return value.
	@Descriptions: 
	1) Swap the two integer pointer value using a temp.
	@Error cases: There is no error case.
*/
void swap(int*n1, int*n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}


/*
	@Function name: void printHeap(HEAP h)
	@Parameters: HEAP h
	@Returns: No return value
	@Descriptions: 
	1) Using the depth and size of the heap, print the elements of the heap array in binary complete tree shape.
	2) Print the depth and size of the heap.
	@Error cases: There is no error case.
*/
void printHeap(HEAP h)
{
	int* d;
	int size;			//buffer size

	d = h->heapData;
	size = h->size;

	int level = findDepth(h);

	printf("Depth = %d, Size = %d\n",level,size);

	int l,w;
	int btw = 4*(int)pow(2,level);
	for(l = 0; l<level; l++)
	{
		printf("%*c",btw/2+1,' ');
		for(w = (int)pow(2,l)-1; w < (int)pow(2,l+1)-1; w++)
		{
			if(w>=size) break;
			int p = *(d+w);
			if(p==0) printf("*");
			else printf("%d",p);
			printf("%*c",btw-1,' ');
		}
		btw/=2;
		printf("\n");
	}
}
