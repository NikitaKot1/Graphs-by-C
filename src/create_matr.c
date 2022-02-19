#include <stdlib.h>
#include <stdio.h>
#include "errorss.h"

void free_matr(int ***a)
{
    free((*a)[0]);
    free(*a);
}

int **allocate_matrix(int n, int m)
{
    int **ptrs, *data;
    ptrs = malloc(n * sizeof(int*));
    if (!ptrs)
        return NULL;
    data = malloc(n * m * sizeof(int));
    if (!data)
    {
        free(ptrs);
        return NULL;
    }
    for (int i = 0; i < n; i++)
        ptrs[i] = data + i * m;
    return ptrs;
}
