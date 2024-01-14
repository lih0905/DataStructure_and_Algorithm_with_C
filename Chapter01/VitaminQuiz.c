#include "LinkedList/LinkedList.h"
#include "DoublyLinkedList/DoublyLinkedList.h"

// 1-1
// sizeof(Node) = 16 // 구조체의 메모리는 가장 큰 변수의 바이트를 기준으로 계산
// sizeof(Node*) = 8 // 포인터는 기본적으로 8바이트

// 1-2
void SLL_InsertBefore(Node **Head, Node *Current, Node *NewHead)
{
    Node *BeforeNode = *Head;

    while (BeforeNode->NextNode != Current)
    {
        BeforeNode = BeforeNode->NextNode;
    }
    BeforeNode->NextNode = NewHead;
    NewHead->NextNode = Current;
}

void SLL_DestroyAllNodes(Node **List)
{
    Node *Head = *List;
    Node *Next;

    while (Head->NextNode != NULL)
    {
        Next = Head->NextNode;
        SLL_DestroyNode(Head);
        Head = Next;
    }

    SLL_DestroyNode(Head);
}

// 1-3
void PrintReverse(Node *Head)
{
    Node *Current = Head;

    while (Current->NextNode != NULL)
    {
        Current = Current->NextNode;
    }

    while (Current != NULL)
    {
        printf("%d\n", Current->Data);
        Current = Current->PrevNode;
    }
}