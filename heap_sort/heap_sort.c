#include "heap_sort.h"
#include "../utils.c"

int main()
{
  Heap H;
  cellOutput = (Cell *)malloc(sizeof(Cell) * MAX_ARR_LEN);

  if (cellOutput != NULL)
  {
    memcpy(cellOutput, data, MAX_ARR_LEN * sizeof(Cell));
    H.arr = cellOutput;
    H.size = MAX_ARR_LEN;

    // minHeapify(&H);
    // minHeapSort(&H);
    maxHeapify(&H);
    maxHeapSort(&H);

    printCellArr(H.arr, H.size);
    free(cellOutput);
  }
}

void minHeapify(Heap *H)
{
  Cell temp;
  int LC, RC, idx, currIdx, smallestIdx, loopFlag = 1;
  // loop from last index to first
  // go up
  for (idx = H->size - 1; idx >= 0; idx--)
  {
    currIdx = idx;
    loopFlag = 1;
    // loop until whole sub tree is heapified
    // go down
    while (loopFlag)
    {
      // select smallest child
      smallestIdx = currIdx;
      LC = idx * 2 + 1;
      RC = idx * 2 + 2;

      if (LC < H->size && H->arr[LC].value < H->arr[currIdx].value)
      {
        smallestIdx = LC;
      }

      if (RC < H->size && H->arr[RC].value < H->arr[smallestIdx].value)
      {
        smallestIdx = RC;
      }

      // not itself = there is smallest child
      if (smallestIdx != currIdx)
      {
        temp = H->arr[currIdx];
        H->arr[currIdx] = H->arr[smallestIdx];
        H->arr[smallestIdx] = temp;
        loopFlag = 1;
      }
      else
      {
        loopFlag = 0;
      }
    }
  }
}

// highest to lowest
void deleteMin(Heap *H)
{
  Cell temp = H->arr[0];
  H->arr[0] = H->arr[H->size - 1];
  H->arr[H->size-- - 1] = temp;
  minHeapify(H);
}

void minHeapSort(Heap *H)
{
  int prevSize = H->size;
  for (int idx = H->size; idx > 0; idx--)
  {
    deleteMin(H);
  }

  H->size = prevSize;
}

void maxHeapify(Heap *H)
{
  Cell temp;
  int LC, RC, largestIdx, currIdx, loopFlag;
  for (int idx = H->size - 1; idx >= 0; idx--)
  {
    currIdx = idx;
    loopFlag = 1;
    while (loopFlag)
    {
      largestIdx = currIdx;
      LC = idx * 2 + 1;
      RC = LC + 1;

      // not out of bounds and child is greater than parent
      if (LC < H->size && H->arr[LC].value > H->arr[currIdx].value)
      {
        largestIdx = LC;
      }

      if (RC < H->size && H->arr[RC].value > H->arr[largestIdx].value)
      {
        largestIdx = RC;
      }

      if (largestIdx != currIdx)
      {
        temp = H->arr[currIdx];
        H->arr[currIdx] = H->arr[largestIdx];
        H->arr[largestIdx] = temp;
        loopFlag = 1;
      }
      else
      {
        loopFlag = 0;
      }
    }
  }
}

void deleteMax(Heap *H)
{
  Cell temp = H->arr[0];
  H->arr[0] = H->arr[H->size - 1];
  H->arr[H->size-- - 1] = temp;
  maxHeapify(H);
}

void maxHeapSort(Heap *H)
{
  int prevSize = H->size;
  for (int idx = H->size; idx > 0; idx--)
  {
    deleteMax(H);
  }

  H->size = prevSize;
}