#include "insertion_sort.h"
#include "../utils.c"

int main()
{
  cellOutput = insertionSort(data, MAX_ARR_LEN);
  printCellArr(cellOutput, MAX_ARR_LEN);
  free(cellOutput);
}

Cell *insertionSort(Cell arr[], int size)
{
  int cellSize = size * sizeof(Cell);
  Cell temp, *output = (Cell *)malloc(cellSize);
  memcpy(output, arr, cellSize);

  for (int i = 1, j; i < size; i++)
  {
    temp = output[i];
    for (j = i; j >= 0 && output[j - 1].value > temp.value; j--)
    {
      output[j] = output[j - 1];
    }
    output[j] = temp;
  }
  return output;
}