#include "comb_sort.h"
#include "../utils.c"

int main()
{
  cellOutput = combSort(data, MAX_ARR_LEN);
  printCellArr(cellOutput, MAX_ARR_LEN);
  free(cellOutput);
}

Cell *combSort(Cell arr[], int size)
{
  int pairCount, hasSwapped = 1;
  Cell *output = (Cell *)malloc(size * sizeof(Cell));
  memcpy(output, arr, size * sizeof(Cell));

  for (int gap = size / SHRINK_FACTOR; gap >= 1 || hasSwapped; gap /= SHRINK_FACTOR)
  {
    hasSwapped = 0;
    pairCount = size - gap;
    for (int i = 0; i < pairCount; i++)
    {
      if (output[i].value > output[i + gap].value)
      {
        swap(&output[i], &output[i + gap]);
        hasSwapped = 1;
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
