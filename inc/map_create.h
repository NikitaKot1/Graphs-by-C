#ifndef MAP_CREATE_H
#define MAP_CREATE_H

#include "struct.h"
void create_map(towns_t **map, int *k, int ***a);
int search_town(towns_t *towns, char *name);

#endif