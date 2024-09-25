#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 10

typedef struct
{
	int arr[MAX];
	int size;
} Heap;

void deleteMax(Heap *);
void heapify(Heap *);
void heapSort(Heap *);
void tournament(int[], int);

void shell(int[], int);
void insertion(int[], int);

void comb(int[], int);
void bubble(int[], int);

void selection(int[], int);
void printArr(int[], int);

int main()
{
	int data[] = {1, 9, 6, 2, 6, 10, 5, 2, 8, 0};
	// Heap *h = (Heap *)malloc(sizeof(Heap));
	// memcpy(h->arr, data, sizeof(int)*MAX);
	// h->size = MAX;
	// heapify(h);
	// heapSort(h);
	// printArr(h->arr, h->size);
	// free(h);
	bubble(data, MAX);
	printArr(data, MAX);
}

void heapify(Heap *H)
{
	int temp, LC, RC, greaterIdx, currIdx;
	char loopFlag = 1;
	for (int i = H->size - 1; i >= 0; i--)
	{
		currIdx = i;
		do
		{
			greaterIdx = currIdx;
			LC = 2 * currIdx + 1;
			RC = LC + 1;

			if (LC < H->size && H->arr[LC] > H->arr[currIdx])
			{
				greaterIdx = LC;
			}
			if (RC < H->size && H->arr[RC] > H->arr[greaterIdx])
			{
				greaterIdx = RC;
			}

			if (currIdx != greaterIdx)
			{
				temp = H->arr[currIdx];
				H->arr[currIdx] = H->arr[greaterIdx];
				H->arr[greaterIdx] = temp;
				currIdx = greaterIdx;
				loopFlag = 1;
			}
			else
			{
				loopFlag = 0;
			}

		} while (loopFlag);
	}
}

void deleteMax(Heap *H)
{
	int temp = H->arr[0];
	H->arr[0] = H->arr[H->size - 1];
	H->arr[H->size-- - 1] = temp;
	heapify(H);
}

void heapSort(Heap *H)
{
	int prevSize = H->size;
	for (int i = 0; i < prevSize; i++)
	{
		deleteMax(H);
	}
	H->size = prevSize;
}

void tournament(int arr[], int size)
{
	int heapSize = 2 * size - 1, startIdx = heapSize - 1, LC, RC;
	int heap[heapSize];
	for (int i = size - 1, j = heapSize - 1; j >= 0; j--)
	{
		heap[j] = i >= 0 ? arr[i--] : INT_MAX;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = (startIdx - 1) / 2; j >= 0;)
		{
			LC = j * 2 + 1;
			RC = LC + 1;

			LC = LC < heapSize - size ? heap[LC] : LC;
			RC = RC < heapSize - size ? heap[RC] : RC;

			heap[j] = heap[RC] < heap[LC] ? RC : LC;

			j = (i > 0 && j != 0) ? (j - 1) / 2 : j - 1;
		}
		startIdx = heap[0];
		arr[i] = heap[startIdx];
		heap[startIdx] = INT_MAX;
	}
}

void shell(int arr[], int size)
{
	int j, temp;
	for (int gap = size / 2; gap >= 1; gap /= 2)
	{
		for (int i = gap; i < size; i++)
		{
			temp = arr[i];
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

void comb(int arr[], int size)
{
	int pairCount, hasSwapped, temp;
	for (int gap = size / 1.3; gap >= 1 || hasSwapped; gap /= 1.3)
	{
		hasSwapped = 0;
		pairCount = size - gap;
		for (int i = 0; i < pairCount; i++)
		{
			if (arr[i] > arr[i + gap])
			{
				temp = arr[i];
				arr[i] = arr[i + gap];
				arr[i + gap] = temp;
				hasSwapped = 1;
			}
		}
	}
}

void insertion(int arr[], int size)
{
	int j, temp;
	for (int i = 1; i < size; i++)
	{
		temp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > temp; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}

void selection(int arr[], int size)
{
	int temp, minKey;
	for (int i = 0; i < size; i++)
	{
		minKey = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[minKey] > arr[j])
			{
				minKey = j;
			}
		}

		if (minKey != i)
		{
			temp = arr[i];
			arr[i] = arr[minKey];
			arr[minKey] = temp;
		}
	}
}

void bubble(int arr[], int size)
{
	int temp, hasSwapped;
	do
	{
		hasSwapped = 0;
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				hasSwapped = 1;
			}
		}
	} while (hasSwapped);
}

void printArr(int arr[], int size)
{
	printf("OUTPUT: [ ");
	for (int i = 0; i < size; i++)
	{
		printf("%d%s", arr[i], i == size - 1 ? " " : ", ");
	}
	printf("]\n");
}
