#include "quick_sort.h"
#include "../utils.c"

int main()
{
  cellOutput = (Cell *)malloc(sizeof(Cell) * MAX_ARR_LEN);
  if (cellOutput != NULL)
  {
    memcpy(cellOutput, data, sizeof(Cell) * MAX_ARR_LEN);
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
    int partIdx = partition(arr, start, end);

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
