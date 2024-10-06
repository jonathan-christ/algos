#ifndef STRAND_SORT_H_
#define STRAND_SORT_H_
#include "../utils.h"

void strandSort(Cell[], Cell[], int *);
void merge(Cell[], Cell[], int *, int);
int extractStrand(Cell[], int, Cell[]);

#endif