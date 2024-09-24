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
  int heapSize = size * 2 - 1, startIdx = heapSize - 1, RC, LC, left, right;
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

      // assignment check
      // check if LEFT CHILD is index or value
      left = LC < heapSize - size ? heap[LC] : LC;
      right = RC < heapSize - size ? heap[RC] : RC;

      heap[j] = heap[left] < heap[right] ? left: right; 


      j = (i > 0 && j != 0) ? (j - 1) / 2 : j - 1;
    }
    startIdx = heap[0];
    arr[i] = heap[startIdx];
    heap[startIdx] = INT_MAX;
  }
}