#include <stdio.h>
#include <string.h>

// 6-1
int Array_SequentialSearch(int Dataset[], int Length, int Target)
{
    int i;

    for (i = 0; i < Length; i++)
    {
        if (Dataset[i] == Target)
        {
            // Index = i;
            if (i >= 1)
            {
                int Temp = Dataset[i];
                memmove(&Dataset[1], &Dataset[0], sizeof(Dataset[0]) * i);
                Dataset[0] = Temp;
            }
            break;
        }
    }

    return i;
}

// 6-2
int Array_Transpose(int Dataset[], int Length, int Target)
{
    int i;

    for (i = 0; i < Length; i++)
    {
        if (Dataset[i] == Target)
        {
            // Index = i;
            if (i >= 1)
            {
                int Temp = Dataset[i];
                Dataset[i] = Dataset[i - 1];
                Dataset[i - 1] = Temp;
            }
            break;
        }
    }

    return i;
}