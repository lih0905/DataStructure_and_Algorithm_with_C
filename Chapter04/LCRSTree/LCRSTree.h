#ifndef LCRSTREE_H
#define LCRSTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagLCRSNode
{
    struct tagLCRSNode *LeftChild;
    struct tagLCRSNode *RightSibling;

    ElementType Data;
} LCRSNode;

LCRSNode *LCRS_CreateNode(ElementType NewData);
void LCRS_DestroyNode(LCRSNode *_Node);
void LCRS_DestroyTree(LCRSNode *Root);

void LCRS_AddChildNode(LCRSNode *Parent, LCRSNode *Child);
void LCRS_PrintTree(LCRSNode *Node, int Depth);
void LCRS_PrintNodeAtLevel(LCRSNode *Root, int Level);

#endif