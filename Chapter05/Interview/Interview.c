#include "Point.h"
#include <stdio.h>

int ComparePoint(Point *P1, Point *P2)
{
    int p1 = P1->point;
    int p2 = P2->point;

    if (p1 > p2)
        return -1;
    else if (p1 < p2)
        return 1;
    return 0;
}

int main(void)
{
    int Length = sizeof(DataSet) / sizeof(DataSet[0]);
    qsort(DataSet, Length, sizeof(Point), ComparePoint);

    for (int i = 0; i < 10; i++)
    {
        printf("%d %f\n", DataSet[i].id, DataSet[i].point);
    }

    printf("14,142th Info\n");
    printf("ID: %d, Point: %f", DataSet[14141].id, DataSet[14141].point);
}