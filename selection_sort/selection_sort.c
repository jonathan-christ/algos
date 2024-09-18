#include "selection_sort.h"
#include "../utils.c"

int main()
{
  cellOutput = selectionSort(data, MAX_ARR_LEN);
  printCellArr(cellOutput, MAX_ARR_LEN);
  free(cellOutput);
}

Cell *selectionSort(Cell arr[], int size)
{
  int minKey, cellSize = size * sizeof(Cell);
  Cell *output = (Cell *)malloc(cellSize);
  memcpy(output, data, cellSize);

  for (int i = 0; i < size; i++)
  {
    // find min
    minKey = i;
    for (int j = i + 1; j < size; j++)
    {
      if (output[minKey].value > output[j].value)
        minKey = j;
    }
    swap(&output[minKey], &output[i]);
  }

  return output;
}

void swap(Cell *A, Cell *B)
{
  Cell temp = *A;
  *A = *B;
  *B = temp;
}
