#include <stdio.h>
#include <stdlib.h>
#include "counting_sort.h"
#include "../utils.c"

int main()
{

	intOutput = countingSortW3(data, MAX_ARR_LEN);
	printIntArr(intOutput, MAX_ARR_LEN);

	cellOutput = countingSortRange(data, MAX_ARR_LEN);
	printCellArr(cellOutput, MAX_ARR_LEN);
}

int *countingSortW3(Cell arr[], int size)
{
	int max = arr[0].value,
			*output = (int *)malloc(size * sizeof(int)), *count;

	for (int x = 1; x < size; x++)
	{
		if (max < arr[x].value)
			max = arr[x].value;
	}

	count = (int *)calloc(max + 1, sizeof(int));

	for (int x = 0; x < size; x++)
	{
		count[arr[x].value]++;
	}

	for (int x = 0, z = 0; x < max + 1; x++)
	{
		for (; count[x] > 0; count[x]--)
		{
			output[z++] = x;
		}
	}

	return output;
}

Cell *countingSortRange(Cell arr[], int size)
{
	int max, min, range, *count;
	Cell *output = (Cell *)malloc(size * sizeof(Cell));

	max = min = arr[0].value;
	// find max and min and range
	for (int i = 1; i < size; i++)
	{
		if (max < arr[i].value)
			max = arr[i].value;
		if (min > arr[i].value)
			min = arr[i].value;
	}

	range = max - min + 1;

	// make count array
	count = (int *)calloc(range, sizeof(int));

	// count elements
	for (int i = 0; i < size; i++)
	{
		count[arr[i].value - min]++;
	}

	// prefix sum
	for (int i = 1; i < range; i++)
	{
		count[i] += count[i - 1];
	}

	// output
	for (int i = size - 1; i >= 0; i--)
	{
		//-1 for index from count, -- for decrement
		output[count[arr[i].value - min]-- - 1] = arr[i];
	}

	return output;
}
