#include <ArrayStack/ArrayStack.h>

// 2-1
// 무슨 의도의 질문인지 모르겠음

// 2-2
int AS_IsFull(ArrayStack *Stack)
{
    return (Stack->Top + 1 == Stack->Capacity);
}
