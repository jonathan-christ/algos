#include <stdio.h>
#include "utils.h"

Cell data[] = {
    {"De Jesus", 2},
    {"Bonghanoy", 5},
    {"Buenavista", 3},
    {"Calaycay", 0},
    {"Ventura", 2},
    {"Modesto", 3},
    {"Tiu", 0},
    {"Sobrecaray", 3}};

void printCellArr(Cell arr[], int size)
{
    printf("OUTPUT:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%20s | %d\n", arr[i].name, arr[i].value);
    }
    printf("\n\n");
}

void printIntArr(int arr[], int size)
{
    printf("OUTPUT: { ");
    for (int i = 0; i < size; i++)
    {
        printf("%d%c ", arr[i], i == size - 1 ? ' ' : ',');
    }
    printf("}\n\n");
}

int *intOutput;
Cell *cellOutput;