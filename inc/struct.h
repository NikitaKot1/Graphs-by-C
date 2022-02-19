#ifndef STRUCT_H
#define STRUCT_H

typedef struct towns towns_t;
struct towns
{
    char name[25];
    int point;
    towns_t *next;
};


#endif