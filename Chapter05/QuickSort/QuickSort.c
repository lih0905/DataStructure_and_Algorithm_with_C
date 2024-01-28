#include <stdio.h>

void Swap(int *A, int *B)
{
    int Temp = *A;
    *A = *B;
    *B = Temp;
}

int Partition(int Dataset[], int Left, int Right)
{
    int First = Left;
    int Pivot = Dataset[First];

    Left++;

    while (Left <= Right)
    {
        while (Dataset[Left] <= Pivot && Left < Right)
            Left++;

        while (Dataset[Right] >= Pivot && Left <= Right)
            Right--;

        if (Left < Right)
            Swap(&Dataset[Left], &Dataset[Right]);
        else
            break;
    }

    Swap(&Dataset[First], &Dataset[Right]);

    return Right;
}

void QuickSort(int Dataset[], int Left, int Right)
{
    if (Left < Right)
    {
        int Index = Partition(Dataset, Left, Right);

        QuickSort(Dataset, Left, Index - 1);
        QuickSort(Dataset, Index + 1, Right);
    }
}

int main(void)
{
    int Dataset[] = {6, 4, 2, 3, 1, 5};
    int Length = sizeof(Dataset) / sizeof(Dataset[0]);

    QuickSort(Dataset, 0, Length - 1);

    for (int i = 0; i < Length; i++)
    {
        printf("%d ", Dataset[i]);
    }

    printf("\n");

    return 0;
}