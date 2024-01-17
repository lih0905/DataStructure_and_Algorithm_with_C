#include "LCRSTree.h"

LCRSNode *LCRS_CreateNode(ElementType NewData)
{
    LCRSNode *NewNode = (LCRSNode *)malloc(sizeof(LCRSNode));

    NewNode->LeftChild = NULL;
    NewNode->RightSibling = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void LCRS_DestroyNode(LCRSNode *_Node)
{
    free(_Node);
}

void LCRS_DestroyTree(LCRSNode *Root)
{
    if (Root->RightSibling != NULL)
    {
        LCRS_DestroyTree(Root->RightSibling);
    }

    if (Root->LeftChild != NULL)
    {
        LCRS_DestroyTree(Root->LeftChild);
    }

    Root->LeftChild = NULL;
    Root->RightSibling = NULL;

    LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRSNode *Parent, LCRSNode *Child)
{
    if (Parent->LeftChild == NULL)
    {
        Parent->LeftChild = Child;
    }
    else
    {
        LCRSNode *TempNode = Parent->LeftChild;
        while (TempNode->RightSibling != NULL)
        {
            TempNode = TempNode->RightSibling;
        }
        TempNode->RightSibling = Child;
    }
}

void LCRS_PrintTree(LCRSNode *Node, int Depth)
{
    // 들여쓰기
    for (int i = 0; i < Depth - 1; i++)
    {
        printf("   ");
    }

    if (Depth > 0) // 자식 노드 여부 표시
        printf("+--");

    // 노드 데이터 출력
    printf("%c\n", Node->Data);

    if (Node->LeftChild != NULL)
    {
        LCRS_PrintTree(Node->LeftChild, Depth + 1);
    }

    if (Node->RightSibling != NULL)
    {
        LCRS_PrintTree(Node->RightSibling, Depth);
    }
}

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