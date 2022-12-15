/*
    double points linklist with head node
*/
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *pre;
    struct DNode *next;
} DNode, *DLinkList;

DLinkList InitList()
{
    DLinkList D = (DLinkList)malloc(sizeof(DNode));
    D->pre = NULL;
    D->next = NULL;
    return D;
}

void toString(DLinkList D)
{
    DNode *p = D->next;
    while (p)
    {
        printf("<->%d", p->data);
        p = p->next;
    }
}

DNode *GetElem(DLinkList D, int i)
{
    if (i == 0)
    {
        return D;
    }
    if (i < 0)
        return NULL;
    DNode *p = D;
    int j = 0;
    while (p && j < i)
    {
        j++;
        p = p->next;
    }
    return p;
}

DNode *GetPreNode(DLinkList D, int i)
{
    DNode *p = GetElem(D, i);
    if (!p->pre)
        return NULL;
    else
        return p->pre;
}
void ListInsert(DLinkList D, int i, ElemType e)
{
    DNode *q = GetElem(D, i - 1);
    DNode *p = (DLinkList)malloc(sizeof(DNode));
    p->data = e;
    p->next = q->next;
    if (q->next)
    {
        q->next->pre = p;
    }
    q->next = p;
    p->pre = q;
}
int main()
{
    DLinkList D = InitList();
    ListInsert(D, 1, 12);
    ListInsert(D, 1, 122);
    ListInsert(D, 1, 22);
    ListInsert(D, 1, 11);
    toString(D);
    printf("\n****************\n");
    int position = 3;
    DNode *p = GetPreNode(D, position);
    printf("the node before position %d is %d\n", position, p->data);
    return 0;
}