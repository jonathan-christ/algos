#ifndef UTILS_H_
#define UTILS_H_

#define MAX_NAME_LEN 20
#define MAX_ARR_LEN 8

typedef struct
{
    char name[MAX_NAME_LEN];
    int value;
} Cell;

void printCellArr(Cell [], int);
void printIntArr(int [], int);

#endif