#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "struct.h"
#include "errorss.h"
#include "create_matr.h"

towns_t *create_town(char *data, int point)
{
    towns_t *node = malloc(sizeof(towns_t));
    if (node)
    {
        strcpy(node->name, data);
        node->point = point;
        node->next = NULL;
    }
    return node;
}

towns_t *append_to_town(towns_t *root, towns_t *node)
{
    towns_t *cur = root;
    if (!root)
        return node;
    for (; cur->next; cur = cur->next);
    cur->next = node;
    return root;
}

int search_town(towns_t *towns, char *name)
{
    for (; towns; towns = towns->next)
        if (!strcmp(name, towns->name))
            return towns->point;
    return -1;
}

int read_road(FILE *f, char *town_start, char *town_end, int *distance)
{
    int rc = fscanf(f, "%s %s %d", town_start, town_end, distance);
    return rc == 3 ? OK : FILE_END;
}

void create_map(towns_t **map, int *k, int ***a)
{
    FILE *f = fopen("roads.txt", "r");
    int dist = 0;
    char t_st[25] = { 0 }, t_end[25] = { 0 };
    int col = 0;
    while (!read_road(f, t_st, t_end, &dist))
    {
        if (search_town(*map, t_st) < 0)
        {
            (*map) = append_to_town(*map, create_town(t_st, col));
            col++;
        }
        if (search_town(*map, t_end) < 0)
        {
            (*map) = append_to_town(*map, create_town(t_end, col));
            col++;
        }
    }
    fclose(f);
    *a = allocate_matrix(col, col);
    for (int i = 0; i < col; i++)
        for (int j = 0; j < col; j++)
            (*a)[i][j] = INT_MAX;
    f = fopen("roads.txt", "r");
    *k = col;
    while (!read_road(f, t_st, t_end, &dist))
    {
        (*a)[search_town(*map, t_st)][search_town(*map, t_end)] = dist;
    }
    fclose(f);
}