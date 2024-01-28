#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ComparePoint(const void *_elem1, const void *_elem2)
{
    int *elem1 = (int *)_elem1;
    int *elem2 = (int *)_elem2;

    if (*elem1 > *elem2)
        return 1;
    else if (*elem1 < *elem2)
        return -1;
    else
        return 0;
}

int ComparePointDescend(const void *_elem1, const void *_elem2)
{
    int *elem1 = (int *)_elem1;
    int *elem2 = (int *)_elem2;

    if (*elem1 > *elem2)
        return -1;
    else if (*elem1 < *elem2)
        return 1;
    else
        return 0;
}

int main(void)
{
    int Dataset[] = {6, 4, 2, 3, 1, 5};
    int Length = sizeof(Dataset) / sizeof(Dataset[0]);

    qsort((void *)Dataset, Length, sizeof(int), ComparePoint);

    for (int i = 0; i < Length; i++)
    {
        printf("%d ", Dataset[i]);
    }
    printf("\n");
    qsort((void *)Dataset, Length, sizeof(int), ComparePointDescend);

    for (int i = 0; i < Length; i++)
    {
        printf("%d ", Dataset[i]);
    }

    return 0;
}