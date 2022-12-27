/*
 * @Descripttion:判断带头结点单链表是否中心对称 如yxy、yxxy
 * @Author: zkb
 * @Date: 2022-12-27 10:44:35
 * @LastEditors: zkb
 * @LastEditTime: 2022-12-27 15:19:12
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 10
typedef struct LNode
{
    char data;
    struct LNode *next;
} LNode, *LinkList;

typedef struct
{
    char *data[MaxSize];
    int top;
} SqStack;
LinkList InitList(char *arr)
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    if (!L)
        return NULL;
    L->next = NULL;
    int length = strlen(arr);
    // int length = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < length; i++)
    {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        p->data = arr[i];
        p->next = L->next;
        L->next = p;
    }
    return L;
}
void InitStack(SqStack *S)
{
    S->top = -1;
}
int Push(SqStack *S, char x)
{
    if (S->top == MaxSize - 1)
        return 0;
    S->data[++S->top] = x;
    return 1;
}

int Pop(SqStack *S, char *x)
{
    if (S->top == -1)
        return 0;
    *x = S->data[S->top--];
    return 1;
}
/**
 * @msg: 判断L是否为中心对称
 * @param {LinkList} L
 * @return {*}
 */
void isSymmetry(LinkList L)
{
    SqStack S;
    InitStack(&S);
    LNode *p = L;
    int length = 0;
    while (p->next)
    {
        length++;
        p = p->next;
    }
    int stackLength = length / 2;
    int evenflag = 1; // 记录长度为奇数或偶数
    if (length % 2 == 1)
    {
        evenflag = 0;
    }
    p = L->next;
    int index = 1;
    while (p)
    {
        if (index <= stackLength)
        {
            Push(&S, p->data);
            p = p->next;
            index++;
        }
        else if (evenflag == 0)
        {
            p = p->next;
            evenflag = 1;
        }
        else
        {
            char tmp;
            Pop(&S, &tmp);
            if (tmp != p->data)
            {
                printf("非中心对称\n");
                return;
            }
            p = p->next;
        }
    }
    printf("中心对称\n");
}
int main()
{
    char arr1[] = "aba";
    char arr2[] = "asdfaczfs";
    LinkList L1 = InitList(arr1);
    LinkList L2 = InitList(arr2);
    isSymmetry(L1);
    isSymmetry(L2);
    return 0;
}