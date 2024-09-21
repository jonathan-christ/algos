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

    minHeapify(&H);
    heapSort(&H);
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

Cell deleteMin(Heap *H)
{
  Cell temp = H->arr[0];
  H->arr[0] = H->arr[H->size - 1];
  H->arr[H->size-- - 1] = temp;
  minHeapify(H);
}

void heapSort(Heap *H)
{
  int prevSize = H->size;
  for (int idx = H->size; idx > 0; idx--)
  {
    deleteMin(H);
  }

  H->size = prevSize;
}
