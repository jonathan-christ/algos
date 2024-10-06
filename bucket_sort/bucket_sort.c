#include "bucket_sort.h"
#include "../utils.c"

int main()
{
  cellOutput = (Cell *)malloc(sizeof(Cell) * MAX_ARR_LEN);
  if (cellOutput != NULL)
  {
    memcpy(cellOutput, data, sizeof(Cell) * MAX_ARR_LEN);
    bucketSort(cellOutput, MAX_ARR_LEN);
    printCellArr(cellOutput, MAX_ARR_LEN);
    free(cellOutput);
  }
  else
  {
    return 0;
  }
}

void bucketSort(Cell arr[], int size)
{
  int i, j, idx, max = arr[0].value, min = max, range, bucketSize;
  Bucket *buckets, *trav, temp;
  // find range
  for (i = 1; i < size; i++)
  {
    if (arr[i].value > max)
      max = arr[i].value;
    if (arr[i].value < min)
      min = arr[i].value;
  }
  range = max - min + 1;

  // int bucket number
  // reporters' orig formula is ideally for large datasets
  // if the range is too small, there would be 0 buckets, so the tweak is as follows
  bucketSize = (range < size) ? size : range / size;
  buckets = (Bucket *)malloc(sizeof(Bucket) * bucketSize);
  for (i = 0; i < bucketSize; i++)
  {
    buckets[i] = NULL;
  }

  // loop through original array, get index of each
  for (i = 0; i < size; i++)
  {
    // idx = (elem-min)*bucketSize / (range+1)
    idx = arr[i].value - min * bucketSize / (range);

    // insert sorted
    for (trav = &buckets[idx]; *trav != NULL && (*trav)->element.value < arr[i].value; trav = &(*trav)->next)
    {
    }

    temp = (Bucket)malloc(sizeof(struct bucketNode));
    if (temp != NULL)
    {
      temp->element = arr[i];
      temp->next = *trav;
      *trav = temp;
    }
  }

  // pour buckets
  for (i = 0, j = 0; i < bucketSize; i++)
  {
    for (temp = buckets[i]; temp != NULL; temp = temp->next)
    {
      cellOutput[j++] = temp->element;
    }
  }
}