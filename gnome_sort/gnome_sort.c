#include "gnome_sort.h"
#include "../utils.c"

int main()
{
  cellOutput = (Cell *)malloc(sizeof(Cell) * MAX_ARR_LEN);
  if (cellOutput != NULL)
  {
    memcpy(cellOutput, data, sizeof(Cell) * MAX_ARR_LEN);
    gnomeSort(cellOutput, MAX_ARR_LEN);
    printCellArr(cellOutput, MAX_ARR_LEN);
    free(cellOutput);
  }
  else
  {
    return 0;
  }
}

void gnomeSort(Cell arr[], int size)
{
  int i = 0;
  Cell temp;
  while (i < size)
  {
    printf("i = %d\n", i);
    if (i != 0 && arr[i].value < arr[i - 1].value)
    {
      temp = arr[i];
      arr[i] = arr[i - 1];
      arr[i - 1] = temp;
      i--;
    }
    else
    {
      i++;
    }
    printCellIteration(arr, size);
  }
}
