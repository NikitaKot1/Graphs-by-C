#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "errorss.h"
#include "struct.h"
#include "print.h"
#include "map_create.h"
#include "timemy.h"
#include "dijkstra.h"

#define PRINT 1
#define FIND 2
#define END 0

void dobey(int *a)
{
    int rc = 0;
    char l[1024];
    while (rc != 1 || *a <= 0)
    {
        fgets(l, sizeof(l), stdin);
        rc = scanf("%d", a);
        if (rc != 1 || *a <= 0)
            printf("Неверный ввод!\nПопробуйте еще раз: ");
    }
}

void dobey_name(char *name, towns_t *towns)
{
    int rc = 0;
    char l[1024];
    int flag = 1;
    while (flag)
    {
        fgets(l, sizeof(l), stdin);
        rc = scanf("%s", name);
        if (rc != 1 || search_town(towns, name) < 0)
            printf("Города не существует!\nПопробуйте еще раз: ");
        else
            flag = 0;
    }
}

int main(void)
{
    setbuf(stdout, NULL);
    char l[1024], name[25] = { 0 };
    int rc = OK, dist = 0, col = 0, *distance = NULL;
    towns_t *map = NULL;
    int **a = NULL;
    create_map(&map, &col, &a);
    if (!rc)
    {
        int tag = -1;
        while (tag)
        {
            printf("Вывести      - %d\n", PRINT);
            printf("Найти города - %d\n", FIND);
            printf("Выйти        - %d\n\n", END);

            scanf("%d", &tag);
            switch (tag)
            {
            case PRINT:
                print_map(map, a, col);
                system("dot -Tpng graphs/map.gv -ographs/map.png");
                break;
            
            case FIND:
                printf("Введите название столицы: ");
                dobey_name(name, map);
                
                printf("Введите расстояние: ");
                dobey(&dist);

                distance = dijkstra_alg(a, search_town(map, name), col);
                for (int i = 0; i < col; i++)
                {
                    if (distance[i] > dist)
                        printf("%s - %s: %d\n", name, find_point(map, i), distance[i]);
                }
                break;

            default:
                fgets(l, sizeof(l), stdin);
                break;
            }
        }

    }
    else
    {
        printf("Ошибка выделения памяти!\n");
    }
    return rc;
}