#include <stdio.h>
#include <string.h>

void InsertionSort(int Dataset[], int Length)
{
    int value = 0;

    for (int i = 1; i < Length; i++)
    {
        if (Dataset[i - 1] <= Dataset[i])
            continue;

        value = Dataset[i];

        for (int j = 0; j < i; j++)
        {
            if (Dataset[j] > value)
            {
                memmove(&Dataset[j + 1], &Dataset[j], sizeof(Dataset[0]) * (i - j));
                Dataset[j] = value;
                break;
            }
        }
    }
}

int main(void)
{
    int Dataset[] = {6, 4, 2, 3, 1, 5};
    int Length = sizeof(Dataset) / sizeof(Dataset[0]);

    InsertionSort(Dataset, Length);

    for (int i = 0; i < Length; i++)
    {
        printf("%d ", Dataset[i]);
    }

    printf("\n");

    return 0;
}