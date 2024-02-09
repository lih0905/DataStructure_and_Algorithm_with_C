#include "LCRSTree/LCRSTree.h"

// 4-1
void LCRS_PrintNodeAtLevel(LCRSNode *Node, int Level)
{
    if (Node != NULL && Level == 0)
    {
        printf("%c\n", Node->Data);
    }

    if (Node->LeftChild != NULL)
    {
        LCRS_PrintNodeAtLevel(Node->LeftChild, Level - 1);
    }

    if (Node->RightSibling != NULL)
    {
        LCRS_PrintNodeAtLevel(Node->RightSibling, Level);
    }
}