#include <stdio.h>
#include <stdlib.h>
#define BUCKET_SIZE 10
#define DECIMAL_DIGITS 10

typedef struct node
{
  int elem;
  struct node *link;
} *List;

void strandS(int arr[], int out[], int *size);
void mergeStr(int out[], int sublist[], int *sizeOut, int sizeTemp);
int extractStr(int arr[], int size, int strand[]);

void quick(int arr[], int start, int end);
int partitionL(int[], int start, int end);
int partitionH(int[], int start, int end);

void mergeS(int arr[], int start, int end);
void merge(int arr[], int start, int middle, int end);

void radix(int arr[], int size);
void countingRadix(int arr[], int size, int exp);
void bucket(int arr[], int size);

void counting(int arr[], int size);
void gnome(int arr[], int size);
void printArr(int arr[], int size);

int main()
{
  int arr[] = {123, 987, 1000, 1, 500, 999, 10000, 789, 0, 50000};
  // int arr[] = {2, 0, 5, 3, 2, 3, 0, 3};
  int size = sizeof(arr) / sizeof(arr[0]);
  int output[size];
  // quick(arr, 0, size - 1);
  strandS(arr, output, &size);
  // radix(arr, size);
  printArr(output, size);
}

void strandS(int arr[], int out[], int *size)
{
  if (*size > 0)
  {
    int strand[*size], strandSize = extractStr(arr, *size, strand);
    *size -= strandSize;
    strandS(arr, out, size);
    mergeStr(out, strand, size, strandSize);
  }
}

int extractStr(int arr[], int size, int strand[])
{
  int i, j, strandSize = 0;
  strand[strandSize++] = arr[0];
  for (i = 1, j = 0; i < size; i++)
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

void mergeStr(int out[], int sublist[], int *sizeOut, int sizeTemp)
{
  int i, j, k, temp[*sizeOut + sizeTemp];
  for (i = 0, j = 0, k = 0; i < *sizeOut && j < sizeTemp; k++)
  {
    temp[k] = (out[i] > sublist[j]) ? sublist[j++] : out[i++];
  }

  for (; j < sizeTemp; j++, k++)
  {
    temp[k] = sublist[j];
  }

  for (; i < *sizeOut; i++, k++)
  {
    temp[k] = out[i];
  }

  // copy to out
  for (i = 0; i < k; i++)
  {
    out[i] = temp[i];
  }

  *sizeOut = k;
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
  int j = start, i = j - 1, temp, pivot = arr[end];
  for (; j < end; j++)
  {
    if (arr[j] < pivot && ++i != j)
    {
      temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;
    }
  }

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
  int i = start - 1, j = end + 1, pivot = arr[start], temp;
  while (i < j)
  {
    do
    {
      i++;
    } while (arr[i] < pivot);

    do
    {
      j--;
    } while (arr[j] > pivot);

    if (i < j)
    {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  return j;
}

void mergeS(int arr[], int start, int end)
{
  if (start < end)
  {
    int middle = (start + end - 1) / 2;

    mergeS(arr, start, middle);
    mergeS(arr, middle + 1, end);
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

  for (i = 0, j = 0, k = start; i < leftSize && j < rightSize; k++)
  {
    arr[k] = left[i] <= right[j] ? left[i++] : right[j++];
  }

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
  int i, exp, max = arr[0];
  for (i = 0; i < size; i++)
  {
    if (max < arr[i])
      max = arr[i];
  }
  for (exp = 1; (max / exp) > 0; exp *= 10)
  {
    // counting sort
    countingRadix(arr, size, exp);
  }
}

void countingRadix(int arr[], int size, int exp)
{
  int i, count[DECIMAL_DIGITS] = {0}, output[size];
  for (i = 0; i < size; i++)
  {
    count[(arr[i] / exp) % DECIMAL_DIGITS]++;
  }

  for (i = 1; i < DECIMAL_DIGITS; i++)
  {
    count[i] += count[i - 1];
  }

  for (i = size - 1; i >= 0; i--)
  {
    output[--count[(arr[i] / exp) % DECIMAL_DIGITS]] = arr[i];
  }

  for (i = 0; i < size; i++)
  {
    arr[i] = output[i];
  }
}

void bucket(int arr[], int size)
{
  // proxmap
  // get min, max,
  // get bucket size

  int i, j, idx, min = arr[0], max = min, bucketSize;
  List temp, *trav, *buckets;

  for (i = 0; i < size; i++)
  {
    if (max < arr[i])
      max = arr[i];
    if (min > arr[i])
      min = arr[i];
  }

  bucketSize = (max - min) < size ? size : (max - min) / size;
  buckets = (List *)malloc(sizeof(List) * bucketSize);
  for (i = 0; i < bucketSize; i++)
  {
    buckets[i] = NULL;
  }

  for (i = 0; i < size; i++)
  {
    idx = (arr[i] - min) * bucketSize / (max - min + 1);

    // insert sorted
    for (trav = &buckets[idx]; *trav != NULL && (*trav)->elem < arr[i]; trav = &(*trav)->link)
    {
    }

    temp = (List)malloc(sizeof(struct node));
    temp->elem = arr[i];
    if (temp != NULL)
    {
      temp->link = *trav;
      *trav = temp;
    }
  }

  for (i = 0, j = 0; i < bucketSize; i++)
  {
    while (buckets[i] != NULL)
    {
      arr[j++] = buckets[i]->elem;
      buckets[i] = buckets[i]->link;
    }
  }
}

void counting(int arr[], int size)
{
  int i, max = arr[0], *count, output[size];
  for (i = 0; i < size; i++)
  {
    if (max < arr[i])
      max = arr[i];
  }

  count = (int *)calloc(max + 1, sizeof(int));
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

void gnome(int arr[], int size)
{
  int i, temp;
  for (i = 0; i < size;)
  {
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