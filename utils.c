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
    {"Sanchez", 6},
    {"Manalili", 1},
    {"Duran", 2},
    {"Pumar", 1},
    {"Manlangit", 0},
    {"Lim", 2},
    {"Singh", 4},
    {"Go", 4}};

int intData[] = {0, 2, 5, 3, 2, 3, 0, 3};
int intDataALT[] = {6, 1, 2, 1, 0, 2, 4, 4};

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

int *intOutput;
Cell *cellOutput;