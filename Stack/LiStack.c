/*
 * @Descripttion:
 * @Author: zkb
 * @Date: 2022-12-22 14:39:50
 * @LastEditors: zkb
 * @LastEditTime: 2022-12-22 15:47:30
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
    LinkNode *p = S;
    while (p->next)
    {
        p = p->next;
    }
    return p;
}
LiStack InitStack()
{
    LiStack S = (LiStack)malloc(sizeof(LinkNode));
    S->next = NULL;
    return S;
}

void Push(LiStack S, ElemType x)
{
    LinkNode *p = getTop(S);
    if (p == NULL)
    {
        LinkNode *q = (LinkNode *)malloc(sizeof(LinkNode));
        q->next = NULL;
        q->data = x;
        S->next = q;
    }
    else
    {
        LinkNode *q = (LinkNode *)malloc(sizeof(LinkNode));
        q->next = p->next;
        q->data = x;
        p->next = q;
    }
}

void Pop(LiStack S, ElemType *x)
{
    LinkNode *q = getTop(S);
    if (q == NULL)
        return;
    LinkNode *p = S;
    while (p->next->next)
    {
        p = p->next;
    }
    p->next = NULL;
    free(q);
}

void toString(LiStack S)
{
    LinkNode *p = S;
    while (p->next)
    {
        printf("->%d", p->next->data);
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