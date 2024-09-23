#include "tournament_sort.h"
#include "../utils.c"

int main()
{
  intOutput = (int *)malloc(sizeof(int) * MAX_ARR_LEN);
  memcpy(intOutput, intDataALT, MAX_ARR_LEN * sizeof(int));
  if (intOutput != NULL)
  {
    indexTournamentSort(intOutput, MAX_ARR_LEN);
    printIntArr(intOutput, MAX_ARR_LEN);
    free(intOutput);
  }
  else
  {
    return 0;
  }
}

void indexTournamentSort(int arr[], int size)
{
  int heapSize = size * 2 - 1, startIdx = heapSize - 1, RC, LC;
  char firstWinFlag = 0;
  int heap[heapSize];
  // fill in heap
  for (int i = size - 1, j = startIdx; j >= 0; j--)
  {
    heap[j] = i >= 0 ? arr[i--] : INT_MAX;
  }

  for (int i = 0; i < size; i++)
  {
    for (int j = (startIdx - 1) / 2; j >= 0;)
    {
      LC = j * 2 + 1;
      RC = LC + 1;

      // if second level parent
      if (j <= heapSize / 4 - 1)
      {
        heap[j] = heap[heap[LC]] < heap[heap[RC]] ? heap[LC] : heap[RC];
      }
      else
      {
        heap[j] = heap[LC] < heap[RC] ? LC : RC;
      }

      j = (firstWinFlag && j != 0) ? (j - 1) / 2 : j - 1;
    }
    startIdx = heap[0];
    arr[i] = heap[startIdx];
    heap[startIdx] = INT_MAX;
    if (!firstWinFlag)
    {
      firstWinFlag = 1;
    }
  }
}