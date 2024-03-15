/********************************************
	Class: Data Structure and Algorithms
	Project 2: Heap and Sort

	main.c

	Name: ÃÖÁø¿ì	
	StudentID: 2019320011
	E-mail: ryan00102@naver.com

**********************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "heap.h"

void printIntro();
void printMenu();
void cmdLoop();

int main()
{
	printIntro();
	cmdLoop();
	return 0;
}

void cmdLoop()
{
	//control params//
	char cmd[100];		//command buffer

	HEAP H = NULL; 				//A static heap pointer variable
	printf("Press [h] to show command lists.\n");
	while(1)
	{
		fflush(stdin);
		gets(cmd);

		if(!strcmp(cmd,"h"))
			printMenu();

		else if(!strcmp(cmd,"D"))
		{
			deleteHeap(H);
			H = NULL;
		}

		else if(!strcmp(cmd,"F"))
			printf("Depth is : %d.\n", findDepth(H));

		else if(!strcmp(cmd,"I"))
		{
			printf("Enter a value : \n");
			char value[100];
			gets(value);
			insertNode(H,atoi(value));
		}

		else if(!strcmp(cmd,"P"))
			printHeap(H);

		else if(!strcmp(cmd,"dh"))
			printf("Dequeue Result : %d\n",dequeueHeap(H));

		else if(!strcmp(cmd,"B"))
		{
			H = createHeap();
			printf("Type values at each line(max=100):\n");
			printf("Type 'x' when you finish\n");
			char value[100];
			int data[100];
			int size = 0;
			while(1)
			{
				gets(value);
				if(!strcmp(value,"x"))
					break;
				data[size] = atoi(value);
				size++;
				if(size>=100)
				{
					printf("Array input Maximized. Force to exit.\n");
					break;
				}
			}
			buildHeap(H,data,size);
			printf("Heap built.\n");
		}

		else if(!strcmp(cmd,"hs"))
		{
			H = createHeap();
			int heapsort[10] = { 13, 9, 47, 2, 88, 71, 98, 59, 91, 63};
			int i;
			printf("--------------------------Array---------------------------\n");
			for(i = 0; i<10; i++)
			{
				printf("%d ", heapsort[i]);
			}
			printf("\n----------------------------------------------------------\n");
			getchar();
			heapSort(H, heapsort,10);
			printf("\n");

			printf("Result : \n");
		    printf("------------------------Heap Sorted-------------------------\n");
			printHeap(H);
			printf("\n");
			printf("------------------------------------------------------------\n");
			getchar();
		}

		else if(!strcmp(cmd,"x"))
		{
			deleteHeap(H);
			printf("Exiting.\n");
			return;
		}

		else if(!strcmp(cmd,""))
			continue;

		else
		{
			printf("You may input wrong command.\n");
			printf("Press [h] to show command lists.\n");
		}

	}
}

void printIntro()
{
	printf("====Data structure & Algorithms====\n");
	printf("|            KECE208_2            |\n");
	printf("|            Project 2            |\n");
	printf("|       Prof. Hwangnam Kim        |\n");
	printf("===================================\n");
	printf("\n");
	return;
}

void printMenu()
{
	printf("Build Heap	[B] \n");
	printf("Delete Heap	[D] \n");
	printf("Find Depth	[F] \n");
	printf("Insert Node	[I] \n");
	printf("Dequeue Heap	[dh]\n");
	printf("Heap Sort	[hs] \n");
	printf("Print Heap	[P] \n");
	printf("Exit		[x] \n");
}