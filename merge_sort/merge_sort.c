#include "merge_sort.h"
#include "../utils.c"

int main()
{
  cellOutput = (Cell *)malloc(sizeof(Cell) * MAX_ARR_LEN);
  if (cellOutput != NULL)
  {
    memcpy(cellOutput, data, sizeof(Cell) * MAX_ARR_LEN);
    mergeSort(cellOutput, 0, MAX_ARR_LEN - 1);
    printCellArr(cellOutput, MAX_ARR_LEN);
    free(cellOutput);
  }
  else
  {
    return 0;
  }
}

void merge(Cell arr[], int start, int middle, int end)
{
  int i, j, k, leftSize = middle - start + 1, rightSize = end - middle;
  // split array into two
  Cell *left = (Cell *)malloc(sizeof(Cell) * leftSize),
       *right = (Cell *)malloc(sizeof(Cell) * rightSize);

  // place all left and right bros
  for (i = 0; i < leftSize; i++)
  {
    left[i] = arr[start + i];
  }
  for (i = 0; i < rightSize; i++)
  {
    right[i] = arr[middle + i + 1];
  }

  // merge the bros
  for (i = 0, j = 0, k = start; i < leftSize && j < rightSize; k++)
  {
    arr[k] = (left[i].value <= right[j].value) ? left[i++] : right[j++];
  }

  // fill remaining
  for (; i < leftSize; i++, k++)
  {
    arr[k] = left[i];
  }

  for (; j < rightSize; j++, k++)
  {
    arr[k] = right[j];
  }

  free(left);
  free(right);
}

void mergeSort(Cell arr[], int start, int end)
{
  if (start < end)
  {
    int middle = start + (end - start) / 2;

    mergeSort(arr, start, middle);
    mergeSort(arr, middle + 1, end);
    merge(arr, start, middle, end);
  }
}
