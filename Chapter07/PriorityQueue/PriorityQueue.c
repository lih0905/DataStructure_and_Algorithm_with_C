#include "PriorityQueue.h"

PriorityQueue *PQ_Create(int InitialSize)
{
    PriorityQueue *NewPQ = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    NewPQ->Capacity = InitialSize;
    NewPQ->UsedSize = 0;
    NewPQ->Nodes = (PQNode *)malloc(sizeof(PQNode) * InitialSize);

    return NewPQ;
}

void PQ_Destroy(PriorityQueue *PQ)
{
    free(PQ->Nodes);
    free(PQ);
}

void PQ_Enqueue(PriorityQueue *PQ, PQNode NewNode)
{
    int CurrentPosition = PQ->UsedSize;
    int ParentPosition = PQ_GetParent(CurrentPosition);

    if (PQ->UsedSize == PQ->Capacity)
    {
        if (PQ->Capacity == 0)
            PQ->Capacity = 1;
        PQ->Capacity *= 2;
        PQ->Nodes = (PQNode *)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
    }

    PQ->Nodes[CurrentPosition] = NewNode;

    // 후속 처리
    while (CurrentPosition > 0 && PQ->Nodes[CurrentPosition].Priority < PQ->Nodes[ParentPosition].Priority)
    {
        PQ_SwapNodes(PQ, CurrentPosition, ParentPosition);

        CurrentPosition = ParentPosition;
        ParentPosition = PQ_GetParent(CurrentPosition);
    }

    PQ->UsedSize++;
}

void PQ_Dequeue(PriorityQueue *PQ, PQNode *Root)
{
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    memcpy(Root, &PQ->Nodes[0], sizeof(PQNode));
    memset(&PQ->Nodes[0], 0, sizeof(PQNode));

    PQ->UsedSize--;
    PQ_SwapNodes(PQ, 0, PQ->UsedSize);

    LeftPosition = PQ_GetLeftChild(0);
    RightPosition = LeftPosition + 1;

    while (1)
    {
        int SelectedPosition = 0;

        if (LeftPosition >= PQ->UsedSize)
            break;

        if (RightPosition >= PQ->UsedSize)
        {
            SelectedPosition = LeftPosition;
        }
        else
        {
            if (PQ->Nodes[LeftPosition].Priority > PQ->Nodes[RightPosition].Priority)
                SelectedPosition = RightPosition;
            else
                SelectedPosition = LeftPosition;
        }

        if (PQ->Nodes[SelectedPosition].Priority < PQ->Nodes[ParentPosition].Priority)
        {
            PQ_SwapNodes(PQ, ParentPosition, SelectedPosition);
            ParentPosition = SelectedPosition;
        }
        else
            break;

        LeftPosition = PQ_GetLeftChild(ParentPosition);
        RightPosition = LeftPosition + 1;
    }

    if (PQ->UsedSize < PQ->Capacity / 2)
    {
        PQ->Capacity /= 2;
        PQ->Nodes = (PQNode *)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
    }
}

int PQ_GetParent(int Index)
{
    return (int)((Index - 1) / 2);
}

int PQ_GetLeftChild(int Index)
{
    return (2 * Index) + 1;
}

void PQ_SwapNodes(PriorityQueue *PQ, int Index1, int Index2)
{
    PQNode *TempNode = (PQNode *)malloc(sizeof(PQNode));
    memcpy(TempNode, &PQ->Nodes[Index1], sizeof(PQNode));
    memcpy(&PQ->Nodes[Index1], &PQ->Nodes[Index2], sizeof(PQNode));
    memcpy(&PQ->Nodes[Index2], TempNode, sizeof(PQNode));
    free(TempNode);
}
int PQ_IsEmpty(PriorityQueue *PQ)
{
    return (PQ->UsedSize == 0);
}