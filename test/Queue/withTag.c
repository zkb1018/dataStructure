/*
 * @Descripttion:设置标志位tag记录队头、队尾指针当前状态是空还是满
 * @Author: zkb
 * @Date: 2022-12-29 14:50:11
 * @LastEditors: zkb
 * @LastEditTime: 2022-12-29 15:26:59
 */
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 5
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
    int tag;
} Queue;

void InitQueue(Queue *Q)
{
    Q->front = Q->rear = Q->tag = 0;
}

void EnQueue(Queue *Q, ElemType x)
{
    if (Q->rear == Q->front && Q->tag == 1)
    {
        printf("队满\n");
        return;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize;
    Q->tag = 1;
}

ElemType DeQueue(Queue *Q)
{
    if (Q->front == Q->rear && Q->tag == 0)
    {
        printf("队空\n");
        return -1;
    }
    ElemType tmp = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    Q->tag = 0;
    return tmp;
}
int main()
{
    Queue Q;
    InitQueue(&Q);
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    DeQueue(&Q);
    DeQueue(&Q);
    DeQueue(&Q);
    return 0;
}