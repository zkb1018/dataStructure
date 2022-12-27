/*
 *   带头节点
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LiStack;

LinkNode *getTop(LiStack S)
{
    if (!S->next)
    {
        printf("栈空\n");
        return NULL;
    }
    return S->next;
}
LiStack InitStack()
{
    LiStack S = (LiStack)malloc(sizeof(LinkNode));
    S->next = NULL;
    return S;
}

void Push(LiStack S, ElemType x)
{

    LinkNode *q = (LinkNode *)malloc(sizeof(LinkNode));
    q->next = S->next;
    q->data = x;
    S->next = q;
}

void Pop(LiStack S, ElemType *x)
{
    LinkNode *q = S->next;
    if (q == NULL)
        return;
    *x = q->data;
    S->next = q->next;
    free(q);
}

void toString(LiStack S)
{
    LinkNode *p = S;
    while (p->next)
    {
        printf("|%4d|\n", p->next->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    LiStack S = InitStack();
    Push(S, 4);
    Push(S, 12);
    Push(S, 33);
    Push(S, 14);
    toString(S);
    int tmp;
    Pop(S, &tmp);
    toString(S);
    return 0;
}