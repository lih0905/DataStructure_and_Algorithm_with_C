#include "LinkedList.h"

#include <string.h>

Node *SLL_SequentialSearch(Node *Head, int Target)
{
    Node *Current = Head;
    Node *Match = NULL;

    while (Current != NULL)
    {
        if (Current->Data == Target)
        {
            Match = Current;
            break;
        }
        else
            Current = Current->NextNode;
    }

    return Match;
}

Node *SLL_MoveToFront(Node **Head, int Target)
{
    Node *Current = (*Head);
    Node *Previous = NULL;
    Node *Match = NULL;

    while (Current != NULL)
    {
        if (Current->Data == Target)
        {
            Match = Current;
            if (Previous != NULL)
            {
                // 자신의 이전 노드와 다음 노드를 연결
                Previous->NextNode = Current->NextNode;

                // 자신을 리스트의 가장 앞으로 옮기기
                Current->NextNode = *Head;
                *Head = Current;
            }
            break;
        }
        else
        {
            Previous = Current;
            Current = Current->NextNode;
        }
    }
    return Match;
}

Node *SLL_Transpose(Node **Head, int Target)
{
    Node *Current = *Head;
    Node *PPrevious = NULL;
    Node *Previous = NULL;
    Node *Match = NULL;

    while (Current != NULL)
    {
        if (Current->Data == Target)
        {
            Match = Current;
            if (Previous != NULL)
            {
                if (PPrevious != NULL)
                    PPrevious->NextNode = Current;
                else
                    *Head = Current;

                Previous->NextNode = Current->NextNode;
                Current->NextNode = Previous;
            }
            break;
        }
        else
        {
            if (Previous != NULL)
                PPrevious = Previous;

            Previous = Current;
            Current = Current->NextNode;
        }
    }
    return Match;
}

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

int main(void)
{
    int Dataset[] = {6, 3, 1, 5, 4, 2};
    int Length = sizeof(Dataset) / sizeof(Dataset[0]);

    printf("Original sequence: ");
    for (int i = 0; i < Length; i++)
    {
        printf("%d ", Dataset[i]);
    }

    int Number = 4;
    int Index = Array_SequentialSearch(Dataset, Length, Number);
    printf("\nThe index of %d is %d\n", Number, Index + 1);

    printf("MoveToFront sequence: ");
    for (int i = 0; i < Length; i++)
    {
        printf("%d ", Dataset[i]);
    }

    Number = 5;
    Index = Array_Transpose(Dataset, Length, Number);
    printf("\nThe index of %d is %d\n", Number, Index + 1);

    printf("Transpose sequence: ");
    for (int i = 0; i < Length; i++)
    {
        printf("%d ", Dataset[i]);
    }

    return 0;
}