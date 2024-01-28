#include <stdio.h>

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

int main(void)
{
    int Dataset[] = {1, 2, 3, 4, 5, 6};
    int Length = sizeof(Dataset) / sizeof(Dataset[0]);

    BubbleSort(Dataset, Length);

    for (int i = 0; i < Length; i++)
    {
        printf("%d ", Dataset[i]);
    }

    printf("\n");

    return 0;
}