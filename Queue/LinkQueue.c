/*
 * @Descripttion:链式队列
 * @Author: zkb
 * @Date: 2022-12-28 15:22:14
 * @LastEditors: KB
 * @LastEditTime: 2023-02-27 14:24:48
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} LinkNode;
typedef struct
{
    LinkNode *rear, *front;
} LinkQueue;

void InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q->front->next = NULL;
}

int IsEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
        return 1;
    else
        return 0;
}

void EnQueue(LinkQueue *Q, ElemType x)
{
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = x;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
}

void DeQueue(LinkQueue *Q, ElemType *x)
{
    if (Q->front == Q->rear)
    {
        printf("队空！\n");
        return;
    }
    LinkNode *p = Q->front->next;
    *x = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
    {
        Q->rear = Q->front;
    }
    free(p);
}
void destroyQueue(LinkQueue *Q){
    while(Q->front!=Q->rear){
        LinkNode *p=Q->front;
        Q->front=p->next;
        free(p);
    }
    free(Q->rear);
}
int main()
{
    LinkQueue Q;
    InitQueue(&Q);
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    int tmp;
    DeQueue(&Q, &tmp);
    destroyQueue(&Q);
    return 0;
}