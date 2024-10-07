#include "strand_sort.h"
#include "../utils.c"

int main()
{
  int size = MAX_ARR_LEN;
  cellOutput = (Cell *)malloc(MAX_ARR_LEN * sizeof(Cell));
  if (cellOutput != NULL)
  {
    strandSort(data, cellOutput, &size);
    printCellArr(cellOutput, MAX_ARR_LEN);
    free(cellOutput);
  }
  else
  {
    return 0;
  }
}

void merge(Cell A[], Cell B[], int *sizeA, int sizeB)
{
  int i, j, k, origSize = *sizeA;
  Cell *temp = (Cell *)malloc((*sizeA + sizeB) * sizeof(Cell));
  for (i = j = k = 0; i < origSize && j < sizeB; k++)
  {
    temp[k] = (B[j].value <= A[i].value) ? B[j++] : A[i++];
  }

  // remaining
  while (j < sizeB)
  {
    temp[k++] = B[j++];
  }

  while (i < origSize)
  {
    temp[k++] = A[i++];
  }

  for (i = 0; i < k; i++)
  {
    A[i] = temp[i];
  }
  *sizeA = k;
  free(temp);
}

int extractStrand(Cell arr[], int size, Cell strand[])
{
  int i, j, strandSize = 0;
  strand[strandSize++] = arr[0];
  printf("extracting first element: %d\n", arr[0].value);

  // do the stranding
  for (i = 1, j = 0; i < size; i++)
  {
    if (arr[i].value >= strand[strandSize - 1].value)
    {
      strand[strandSize++] = arr[i];
    }
    else
    {
      arr[j++] = arr[i]; // shift
    }
  }

  return strandSize;
}

void strandSort(Cell arr[], Cell out[], int *size)
{
  if (*size > 0)
  {
    Cell *strand = (Cell *)malloc(sizeof(Cell) * (*size));
    int strandSize = extractStrand(arr, *size, strand);

    printf("\nSTRAND: \n");
    printCellArr(strand, strandSize);
    // input array has reduced size now
    *size -= strandSize;

    strandSort(arr, out, size);

    merge(out, strand, size, strandSize);
    printf("\nMERGING: \n");
    printCellArr(out, *size);
    free(strand);
  }
}