#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

Cell data[] = {
    {"Calaycay", 0},
    {"De Jesus", 2},
    {"Bonghanoy", 5},
    {"Buenavista", 3},
    {"Ventura", 2},
    {"Modesto", 3},
    {"Tiu", 0},
    {"Sobrecaray", 3}};

Cell dataALT[] = {
    {"Calaycay", 6},
    {"De Jesus", 1},
    {"Bonghanoy", 2},
    {"Buenavista", 1},
    {"Ventura", 0},
    {"Modesto", 2},
    {"Tiu", 4},
    {"Sobrecaray", 4}};

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