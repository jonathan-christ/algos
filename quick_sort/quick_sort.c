#include "quick_sort.h"
#include "../utils.c"

int main()
{
  cellOutput = (Cell *)malloc(sizeof(Cell) * MAX_ARR_LEN);
  if (cellOutput != NULL)
  {
    memcpy(cellOutput, dataALT, sizeof(Cell) * MAX_ARR_LEN);
    quickSort(cellOutput, 0, MAX_ARR_LEN - 1);
    printCellArr(cellOutput, MAX_ARR_LEN);
    free(cellOutput);
  }
  else
  {
    return 0;
  }
}

void quickSort(Cell arr[], int start, int end)
{
  if (start < end)
  {
    int partIdx = partitionHoare(arr, start, end);

    quickSort(arr, start, partIdx - 1);
    quickSort(arr, partIdx + 1, end);
  }
}

int partition(Cell arr[], int start, int end)
{
  Cell temp;
  int i = start - 1, j, pivot = arr[end].value;

  // two iterators, i looking before, j looking ahead
  // should be before last idx (pivot implementation)
  for (j = start, i = start - 1; j < end; j++)
  {
    // only increment i when an element is less or greater than the pivot (condition)
    if (arr[j].value < pivot)
    {
      // swap
      temp = arr[j];
      arr[j] = arr[++i];
      arr[i] = temp;
    }
  }

  // replace pivot with its proper position in parition
  // proper position is one the first arr[j] thats > pivot
  temp = arr[++i];
  arr[i] = arr[end];
  arr[end] = temp;

  return i;
}

// two pointer method
int partitionHoare(Cell arr[], int start, int end)
{
  Cell temp;
  int i = start, j = end, k, pivot = arr[start].value;

  // sift values until two pointers cross each other
  while (i < j)
  {
    // move until left side has inversion (val > pivot)
    for (; i < j && arr[i].value < pivot; i++)
    {
    }
    // move until right has inversion (val < pivot)
    for (; j > i && arr[j].value > pivot; j--)
    {
    }

    // swap if inversion is found
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }

  return i;
}
