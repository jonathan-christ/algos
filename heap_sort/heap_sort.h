#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_
#include "../utils.h"

typedef struct
{
  Cell *arr;
  int size;
} Heap;

void minHeapify(Heap *);
void maxHeapify(Heap *);

void deleteMin(Heap *);
void deleteMax(Heap *);

void minHeapSort(Heap *);
void maxHeapSort(Heap *);
#endif