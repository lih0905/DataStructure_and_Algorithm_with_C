#include <stdio.h>

// 5-1
void BubbleSort(int Dataset[], int Length)
{
    int temp = 0;
    int sortcount = 0;
    int totalcount = 0;

    for (int i = 0; i < Length - 1; i++)
    {
        sortcount = 0;
        for (int j = 0; j < Length - 1; j++)
        {
            if (Dataset[j] > Dataset[j + 1])
            {
                temp = Dataset[j + 1];
                Dataset[j + 1] = Dataset[j];
                Dataset[j] = temp;
                sortcount++;
            }
        }
        if (sortcount == 0)
            break;
    }
}

// 5-2
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