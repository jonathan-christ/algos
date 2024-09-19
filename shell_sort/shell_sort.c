#include "shell_sort.h"
#include "../utils.c"

int main()
{
  // cellOutput = shellSortN2(data, MAX_ARR_LEN);
  cellOutput = shellSortFixedGap(data, MAX_ARR_LEN);
  printCellArr(cellOutput, MAX_ARR_LEN);
  free(cellOutput);
}

Cell *shellSortN2(Cell arr[], int size)
{
  Cell *output = (Cell *)malloc(size * sizeof(Cell));
  memcpy(output, arr, size * sizeof(Cell));

  for (int gap = size / 2; gap > 0; gap /= 2)
  {
    modifiedInsertion(output, size, gap);
  }

  return output;
}

Cell *shellSortFixedGap(Cell arr[], int size)
{
  int chosenGap = 1;
  int gaps[][8] = {
      // toyota idk
      {701, 301, 132, 57, 23, 10, 4, 1},
      // sedgewick
      {929, 505, 209, 109, 41, 19, 5, 1}};
  int gapSize = sizeof(gaps[chosenGap]) / sizeof(gaps[chosenGap][0]);

    Cell *output = (Cell *)malloc(size * sizeof(Cell));
  memcpy(output, arr, size * sizeof(Cell));

  for (int gapIdx = 0; gapIdx < gapSize; gapIdx++)
  {
    if (gaps[chosenGap][gapIdx] < size)
    {
      modifiedInsertion(output, size, gaps[chosenGap][gapIdx]);
    }
  }

  return output;
}

void modifiedInsertion(Cell arr[], int size, int gap)
{
  Cell temp;
  int j;
  for (int i = gap; i < size; i++)
  {
    temp = arr[i];
    for (j = i; j >= gap && arr[j - gap].value > temp.value; j -= gap)
    {
      arr[j] = arr[j - gap];
    }
    arr[j] = temp;
  }
}
