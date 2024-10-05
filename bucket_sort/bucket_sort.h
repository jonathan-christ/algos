#ifndef BUCKET_SORT_H_
#define BUCKET_SORT_H_
#include "../utils.h"

typedef struct bucketNode {
  Cell element;
  struct bucketNode *next;
} *Bucket;

void bucketSort(Cell [], int);

#endif