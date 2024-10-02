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
  int i, j, LC, RC, heapSize = size * 2 - 1, startIdx = heapSize - 1;
  int *heap = (int *)malloc(sizeof(int) * heapSize);
  for (i = size - 1, j = startIdx; i >= 0; i--, j--)
  {
    heap[j] = arr[i];
  }

  for (i = 0; i < size; i++)
  {
    for (j = (startIdx - 1) / 2; j >= 0;)
    {
      LC = 2 * j + 1;
      RC = LC + 1;

      LC = LC < heapSize - size ? heap[LC] : LC;
      RC = RC < heapSize - size ? heap[RC] : RC;

      heap[j] = heap[LC] <= heap[RC] ? LC : RC;
      j = (i > 0 && j > 0) ? (j - 1) / 2 : j - 1;
    }
    startIdx = heap[0];
    arr[i] = heap[startIdx];
    heap[startIdx] = INT_MAX;
  }
}

void heapSort(Heap *H)
{
  int i, prevSize = H->size;
  for (i = 0; i < prevSize; i++)
  {
    deleteMax(H);
  }
  H->size = prevSize;
}

void deleteMax(Heap *H)
{
  if (H->size > 0)
  {
    int temp = H->arr[0];
    H->arr[0] = H->arr[--H->size];
    H->arr[H->size] = temp;
    heapify(H, 0);
  }
}

void heapify(Heap *H, int idx)
{
  int LC = idx * 2 + 1, RC = LC + 1, greatestIdx = idx, temp;

  if (LC < H->size && H->arr[LC] > H->arr[greatestIdx])
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

void arrayToHeap(Heap *H, int arr[], int size)
{
  int i, j, temp;
  H->size = 0;
  for (i = 0; i < size; i++)
  {
    H->arr[H->size++] = arr[i];
    for (j = H->size - 1; j > 0; j = (j - 1) / 2)
    {
      // max heap, parent greater
      if (H->arr[j] > H->arr[(j - 1) / 2])
      {
        temp = H->arr[j];
        H->arr[j] = H->arr[(j - 1) / 2];
        H->arr[(j - 1) / 2] = temp;
      }
    }
  }
}

void shell(int arr[], int size)
{
  int i, j, gap, temp;
  for (gap = size / 2; gap > 0; gap /= 2)
  {
    for (i = gap; i < size; i++)
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
  int i, gap, pairCount, temp, hasSwapped = 1;
  for (gap = size / 1.3; gap > 0 || hasSwapped; gap /= 1.3)
  {
    hasSwapped = 0;
    pairCount = size - gap;
    for (i = 0; i < pairCount; i++)
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
  int i, j, temp;
  for (i = 1; i < size; i++)
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
  int i, j, min, temp;
  for (i = 0; i < size; i++)
  {
    for (j = i + 1, min = i; j < size; j++)
    {
      if (arr[min] > arr[j])
      {
        min = j;
      }
    }
    if (min != i)
    {
      temp = arr[min];
      arr[min] = arr[i];
      arr[i] = temp;
    }
  }
}

void bubble(int arr[], int size)
{
  int i, j, temp, hasSwapped = 1;
  for (i = 1; i < size && hasSwapped; i++)
  {
    hasSwapped = 0;
    for (j = 0; j < size - i; j++)
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

void printArr(int data[], int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("%d ", data[i]);
  }
  printf("\n");
}