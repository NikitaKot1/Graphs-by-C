#include <stdio.h>

#include "struct.h"
#include "errorss.h"

void print_dipend(FILE *f, char *x, char *y, int dist)
{
    fprintf(f, "    \"%s\" -> \"%s\" [label=%d];\n", x, y, dist);
}

char *find_point(towns_t *towns, int point)
{
    for (; towns; towns = towns->next)
        if (towns->point == point)
            return towns->name;
    return NULL;
}

void print_map(towns_t *towns, int **a, int col)
{
    FILE *f = fopen("graphs/map.gv", "w");
    fprintf(f, "digraph Map {\n");
    
    for (int i = 0; i < col; i++)
        for (int j = 0; j < col; j++)
            if (a[i][j] != __INT_MAX__)
                print_dipend(f, find_point(towns, i), find_point(towns, j), a[i][j]);

    fprintf(f, "}");
    fclose(f);
}