/*
 * @Descripttion:删除倒数第n个结点(双指针)
 * @Author: zkb
 * @Date: 2022-12-30 14:37:45
 * @LastEditors: zkb
 * @LastEditTime: 2022-12-30 15:20:47
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

LNode *InitList()
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->data = -1;
    L->next = NULL;
    return L;
}
void InitTestList(LinkList L)
{
    int num = 5;
    for (int i = 0; i < num; i++)
    {
        int tmp = rand() % 100;
        LNode *p = (LinkList)malloc(sizeof(LNode));
        p->data = tmp;
        p->next = L->next;
        L->next = p;
    }
}
void toString(LinkList L)
{
    LNode *p = L->next;
    while (p)
    {
        printf("->%d", p->data);
        p = p->next;
    }
    printf("\n");
}
/**
 * @msg: 删除倒数第n个结点
 * @param {LinkList} L
 * @param {int} n
 * @return {*}
 */
void DelNToLast(LinkList L, int n)
{
    LNode *p, *q;
    p = q = L;
    q->data = -1;
    int i = 0;
    while (p->next)
    {
        p = p->next;
        if (i >= n)
        {
            q = q->next;
        }
        i++;
    }
    if (q->data != -1)
    {
        LNode *o = q->next;
        q->next = q->next->next;
        free(o);
    }
}
int main()
{
    LinkList L = InitList();
    InitTestList(L);
    toString(L);
    DelNToLast(L, 4);
    toString(L);
    return 0;
}