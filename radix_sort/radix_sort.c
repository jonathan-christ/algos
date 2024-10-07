#include "radix_sort.h"
#include "../utils.c"

int main()
{
  cellOutput = (Cell *)malloc(sizeof(Cell) * MAX_ARR_LEN);
  if (cellOutput != NULL)
  {
    memcpy(cellOutput, dataALT, sizeof(Cell) * MAX_ARR_LEN);
    radixSort(cellOutput, MAX_ARR_LEN);
    printCellArr(cellOutput, MAX_ARR_LEN);
    free(cellOutput);
  }
  else
  {
    return 0;
  }
}

// modified for radix, using decimal (number system) places
void countingSort(Cell arr[], int size, int place)
{
  // no need to find range anymore
  // count size = no. of digits in base (0-9 aka 10 for decimals)
  int i, j, count[DECIMAL_DIGIT_COUNT] = {0};
  Cell output[size];

  // getting the count of each element's selected digit place
  for (i = 0; i < size; i++)
  {
    count[(arr[i].value / place) % DECIMAL_DIGIT_COUNT]++;
  }

  // getting prefix sum
  for (i = 1; i < DECIMAL_DIGIT_COUNT; i++)
  {
    count[i] += count[i - 1];
  }

  // filling output array (always start at back)
  for (i = size-1; i >= 0; i--)
  {
    output[count[(arr[i].value / place) % 10]-- - 1] = arr[i];
  }

  memcpy(arr, output, size * sizeof(Cell));
}

// LSD implementation (better overall)
void radixSort(Cell arr[], int size)
{
  int i, place, max = arr[0].value;
  for (i = 1; i < size; i++)
  {
    if (max < arr[i].value)
      max = arr[i].value;
  }

  // end loop after biggest number's MSD (most sig. digit) max/place
  for (place = 1; max / place > 0; place *= 10)
  {
    countingSort(arr, size, place);
    printCellIteration(arr, size);
  }
}
