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
void arrayToHeap(Heap *, int[], int);
void heapify(Heap *, int);
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
  // arrayToHeap(h, data, MAX);
  // printArr(h->arr, h->size);
  // heapSort(h);
  // printArr(h->arr, h->size);
  // free(h);
  tournament(data, MAX);
  printArr(data, MAX);
}

void tournament(int arr[], int size)
{
  int temp, LC, RC;
  int heapSize = size * 2 - 1, startIdx = heapSize - 1;
  int heap[heapSize];
  for (int i = size - 1, j = startIdx; i >= 0; i--, j--)
  {
    heap[j] = arr[i];
  }

  // fill array
  for (int i = 0; i < size; i++)
  {
    for (int j = (startIdx - 1) / 2; j >= 0;)
    {
      LC = 2 * j + 1;
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

void heapSort(Heap *H)
{
  int prevSize = H->size;
  for (int i = 0; i < prevSize; i++)
  {
    deleteMax(H);
  }
  H->size = prevSize;
}

void deleteMax(Heap *H)
{
  int temp = H->arr[0];
  H->arr[0] = H->arr[H->size - 1];
  H->arr[H->size-- - 1] = temp;
  heapify(H, 0);
}

void arrayToHeap(Heap *H, int arr[], int size)
{
  int temp;
  H->size = 0;
  for (int i = 0; i < size; i++)
  {
    H->arr[H->size++] = arr[i];
    for (int j = H->size - 1; j > 0 && H->arr[(j - 1) / 2] < H->arr[j]; j = (j - 1) / 2)
    {
      temp = H->arr[(j - 1) / 2];
      H->arr[(j - 1) / 2] = H->arr[j];
      H->arr[j] = temp;
    }
  }
}

void heapify(Heap *H, int idx)
{
  int LC = idx * 2 + 1, RC = LC + 1, greatestIdx = idx, temp;
  if (LC < H->size && H->arr[LC] > H->arr[idx])
  {
    greatestIdx = LC;
  }

  if (RC < H->size && H->arr[RC] > H->arr[greatestIdx])
  {
    greatestIdx = RC;
  }

  if (greatestIdx != idx)
  {
    temp = H->arr[greatestIdx];
    H->arr[greatestIdx] = H->arr[idx];
    H->arr[idx] = temp;
    heapify(H, greatestIdx);
  }
}

void shell(int arr[], int size)
{
  int temp, gap;
  for (gap = size / 2; gap > 0; gap /= 2)
  {
    for (int i = gap, j; i < size; i++)
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
  int pairCount, temp, hasSwaps, gap;
  for (gap = size / 1.3; gap >= 1 || hasSwaps; gap /= 1.3)
  {
    pairCount = size - gap;
    hasSwaps = 0;
    for (int i = 0; i < pairCount; i++)
    {
      if (arr[i + gap] < arr[i])
      {
        temp = arr[i];
        arr[i] = arr[i + gap];
        arr[i + gap] = temp;
        hasSwaps = 1;
      }
    }
  }
}

void insertion(int arr[], int size)
{
  int temp;
  for (int i = 1, j; i < size; i++)
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
  int temp, min;
  for (int i = 0; i < size; i++)
  {
    min = i;
    for (int j = i + 1; j < size; j++)
    {
      if (arr[min] > arr[j])
      {
        min = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}

void bubble(int arr[], int size)
{
  int temp;
  for (int i = 1, hasSwapped = 1; i < size && hasSwapped; i++)
  {
    hasSwapped = 0;
    for (int j = 0; j < size - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        hasSwapped = 1;
      }
    }
  }
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