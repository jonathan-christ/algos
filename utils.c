#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

Cell data[] = {
    {"De Jesus", 2},
    {"Calaycay", 0},
    {"Bonghanoy", 5},
    {"Buenavista", 3},
    {"Ventura", 2},
    {"Modesto", 3},
    {"Tiu", 0},
    {"Sobrecaray", 3}};

Cell dataALT[] = {
    {"Sanchez", 632},
    {"Manalili", 12},
    {"Duran", 23},
    {"Pumar", 1},
    {"Manlangit", 100},
    {"Lim", 72},
    {"Singh", 4},
    {"Go", 455}};

int intData[] = {0, 2, 5, 3, 2, 3, 0, 3};
int intDataALT[] = {632, 12, 23, 1, 100, 72, 4, 455};

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
        printf("%d%s", arr[i], i == size - 1 ? " " : ", ");
    }
    printf("}\n\n");
}

void printCellIteration(Cell arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i].value);
    }
    printf("\n\n");
}

void printIntIteration(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int *intOutput;
Cell *cellOutput;