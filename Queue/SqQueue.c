/*
 * @Descripttion:循环队列  普通队列易发生上溢，使用循环队列提高资源利用率
 * @Author: zkb
 * @Date: 2022-12-28 14:19:25
 * @LastEditors: zkb
 * @LastEditTime: 2022-12-29 09:27:54
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 5
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue *Q)
{

    //*Q->data = {0};
    memset(Q->data, 0, MaxSize);
    Q->front = Q->rear = 0; // 队空 front==rear
}

/**
 * @msg: 入队
 * @param {SqQueue} *Q
 * @param {ElemType} x
 * @return {*}
 */
int EnQueue(SqQueue *Q, ElemType x)
{
    if ((Q->rear + 1) % MaxSize == Q->front)
    {
        printf("队满！\n");
        return 0;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize;
    return 1;
}

int DeQueue(SqQueue *Q, ElemType *x)
{
    if (Q->front == Q->rear)
    {
        printf("队空!\n");
        return 0;
    }
    *x = Q->data[Q->front];
    Q->data[Q->front] = 0;
    Q->front = (Q->front + 1) % MaxSize;
    return 1;
}
int main()
{
    SqQueue Q;
    InitQueue(&Q);
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    EnQueue(&Q, 4);
    EnQueue(&Q, 5);
    int out;
    DeQueue(&Q, &out);
    DeQueue(&Q, &out);

    return 0;
}