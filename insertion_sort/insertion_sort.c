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
  Cell *output = (Cell *)malloc(cellSize);
  memcpy(output, arr, cellSize);

  for (int i = 1; i < size; i++)
  {
    for (int j = i - 1; j >= 0 && output[j].value > output[j + 1].value; j--)
    {
      swap(&output[j + 1], &output[j]);
    }
  }
  return output;
}

void swap(Cell *A, Cell *B)
{
  Cell temp = *A;
  *A = *B;
  *B = temp;
}