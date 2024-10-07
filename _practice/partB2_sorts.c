#include <stdio.h>
#include <stdlib.h>
#define BUCKET_SIZE 10
#define DECIMAL_DIGITS 10

typedef struct node
{
  int elem;
  struct node *link;
} *List;

void strandSort(int arr[], int out[], int *size);
void mergeStrand(int out[], int sublist[], int *sizeOut, int sizeTemp);
int extractStrand(int arr[], int size, int strand[]);

void quick(int arr[], int start, int end);
int partitionL(int[], int start, int end);
int partitionH(int[], int start, int end);

void mergeSort(int arr[], int start, int end);
void merge(int arr[], int start, int middle, int end);

void radix(int arr[], int size);
void countingRadix(int arr[], int size, int exp);
void bucketSort(int arr[], int size);

void counting(int arr[], int size);
void gnome(int arr[], int size);
void printArr(int arr[], int size);

int main()
{
  // int arr[] = {123, 987, 1000, 1, 500, 999, 10000, 789, 0, 50000};
  // int arr[] = {8, 5, 1, 7, 3};
  int arr[] = {2, 0, 5, 3, 2, 0, 3};
  int size = sizeof(arr) / sizeof(arr[0]);
  // int output[size];
  // quick(arr, 0, size - 1);
  // strandSort(arr, output, &size);
  gnome(arr, size);
  printArr(arr, size);
}

void strandSort(int arr[], int out[], int *size)
{
  if (*size > 0)
  {
    int strand[*size], strandSize = extractStrand(arr, *size, strand);
    *size -= strandSize;

    strandSort(arr, out, size);
    mergeStrand(out, strand, size, strandSize);
  }
}

void mergeStrand(int out[], int sublist[], int *sizeOut, int sizeSub)
{
  int i, j, k, temp[*sizeOut + sizeSub];
  for (i = j = k = 0; i < *sizeOut && j < sizeSub; k++)
  {
    temp[k] = (sublist[j] <= out[i]) ? sublist[j++] : out[i++];
  }

  // remaining
  while (j < sizeSub)
  {
    temp[k++] = sublist[j++];
  }

  while (i < *sizeOut)
  {
    temp[k++] = out[i++];
  }

  for (i = 0; i < k; i++)
  {
    out[i] = temp[i];
  }

  *sizeOut = k;
}

int extractStrand(int arr[], int size, int strand[])
{
  int i, j, strandSize;
  strand[0] = arr[0];
  for (i = 1, j = 0, strandSize = 1; i < size; i++)
  {
    if (arr[i] >= strand[strandSize - 1])
    {
      strand[strandSize++] = arr[i];
    }
    else
    {
      arr[j++] = arr[i];
    }
  }

  return strandSize;
}

void quick(int arr[], int start, int end)
{
  if (start < end)
  {
    int idx = partitionH(arr, start, end);

    quick(arr, start, idx);
    quick(arr, idx + 1, end);
  }
}

int partitionL(int arr[], int start, int end)
{
  int i, j, temp, pivot = arr[end];
  for (j = start, i = j - 1; j < end; j++)
  {
    if (arr[j] < pivot && ++i != j)
    {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  // swap pivot to i
  if (++i != end)
  {
    temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;
  }

  return i;
}

int partitionH(int arr[], int start, int end)
{
  int i, j, temp, pivot = arr[start];
  for (i = start, j = end; i < j;)
  {
    while (i < j && arr[i] < pivot)
      i++;
    while (i < j && arr[j] > pivot)
      j--;

    if (i < j)
    {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  return j;
}

void mergeSort(int arr[], int start, int end)
{
  if (start < end)
  {
    int i, middle = (end + start) / 2;

    mergeSort(arr, start, middle);
    mergeSort(arr, middle + 1, end);
    merge(arr, start, middle, end);
  }
}

void merge(int arr[], int start, int middle, int end)
{
  int i, j, k, leftSize = middle - start + 1, rightSize = end - middle;
  int left[leftSize], right[rightSize];
  for (i = 0, j = start; i < leftSize; i++, j++)
  {
    left[i] = arr[j];
  }
  for (i = 0; i < rightSize; i++, j++)
  {
    right[i] = arr[j];
  }

  // combine
  for (i = 0, j = 0, k = start; i < leftSize && j < rightSize; k++)
  {
    arr[k] = (left[i] <= right[j]) ? left[i++] : right[j++];
  }

  // combine remaining
  while (i < leftSize)
  {
    arr[k++] = left[i++];
  }

  while (j < rightSize)
  {
    arr[k++] = right[j++];
  }
}

void radix(int arr[], int size)
{
  int i, max = arr[0], exp = 1;
  for (i = 0; i < size; i++)
  {
    if (arr[i] > max)
      max = arr[i];
  }

  for (; (max / exp) > 0; exp *= 10)
  {
    countingRadix(arr, size, exp);
  }
}

void countingRadix(int arr[], int size, int exp)
{
  int i, count[DECIMAL_DIGITS] = {0}, output[size];
  // get digits check
  // get count
  for (i = 0; i < size; i++)
  {
    count[(arr[i] / exp) % DECIMAL_DIGITS]++;
  }

  // get prefix sum
  for (i = 1; i < DECIMAL_DIGITS; i++)
  {
    count[i] += count[i - 1];
  }

  // get output
  for (i = size - 1; i >= 0; i--)
  {
    output[--count[(arr[i] / exp) % DECIMAL_DIGITS]] = arr[i];
  }

  // place to main
  for (i = 0; i < size; i++)
  {
    arr[i] = output[i];
  }
}

void bucketSort(int arr[], int size)
{
  List temp, *trav, *bucket;
  int i, idx, bucketSize, min = arr[0], max = min;
  // get bucket size
  for (i = 0; i < size; i++)
  {
    if (arr[i] > max)
      max = arr[i];
    if (arr[i] < max)
      min = arr[i];
  }

  bucketSize = (max - min < size) ? size : (max - min) / size;
  bucket = (List *)malloc(sizeof(List) * bucketSize);
  if (bucket != NULL)
  {
    // set null
    for (i = 0; i < bucketSize; i++)
    {
      bucket[i] = NULL;
    }
    // list to buckets
    for (i = 0; i < size; i++)
    {
      idx = (arr[i] - min) * bucketSize / (max - min + 1);
      // insert sorted
      for (trav = &bucket[idx]; *trav != NULL && (*trav)->elem < arr[i]; trav = &(*trav)->link)
      {
      }

      temp = (List)malloc(sizeof(struct node));
      if (temp != NULL)
      {
        temp->elem = arr[i];
        temp->link = *trav;
        *trav = temp;
      }
    }

    // unload buckets
    for (i = 0, idx = 0; i < bucketSize; i++)
    {
      while (bucket[i] != NULL)
      {
        arr[idx++] = bucket[i]->elem;
        bucket[i] = bucket[i]->link;
      }
    }
  }
}

void counting(int arr[], int size)
{
  int i, j, max = arr[0], *count, output[size];
  // find max
  for (i = 0; i < size; i++)
  {
    if (max < arr[i])
      max = arr[i];
  }

  count = (int *)calloc(max + 1, sizeof(int));
  if (count != NULL)
  {
    for (i = 0; i < size; i++)
    {
      count[arr[i]]++;
    }

    // prefix sum
    for (i = 1; i <= max; i++)
    {
      count[i] += count[i - 1];
    }

    for (i = size - 1; i >= 0; i--)
    {
      output[--count[arr[i]]] = arr[i];
    }

    for (i = 0; i < size; i++)
    {
      arr[i] = output[i];
    }
  }
}

void gnome(int arr[], int size)
{
  int i, temp, k = 0;
  for (i = 0; i < size;)
  {
    printf("[%d] i = %d\n", k++, i);
    if (i != 0 && arr[i] < arr[i - 1])
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
    printArr(arr, size);
  }
}

void printArr(int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}