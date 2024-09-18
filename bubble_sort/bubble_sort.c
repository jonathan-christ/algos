#include "bubble_sort.h"
#include "../utils.c"

int main()
{
  cellOutput = bubbleSort(data, MAX_ARR_LEN);
  printCellArr(cellOutput, MAX_ARR_LEN);
  free(cellOutput);
}

Cell *bubbleSort(Cell arr[], int size)
{
  int memSize = size * sizeof(Cell);
  Cell temp, *output = (Cell *)malloc(memSize);
  memcpy(output, arr, memSize);

  for (int j = 0; j < size; j++)
  {
    for (int i = 1; i < size - j; i++)
    {
      if (output[i - 1].value > output[i].value)
      {
        swap(&output[i-1], &output[i]);
      }
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