/*
 * @Descripttion:借助栈逆置队列
 * @Author: zkb
 * @Date: 2022-12-29 15:29:05
 * @LastEditors: zkb
 * @LastEditTime: 2022-12-29 15:50:29
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
typedef struct
{
    ElemType data[MaxSize];
    int top;
} SqStack;
void InitStack(SqStack *S)
{
    S->top = -1;
}

int Push(SqStack *S, ElemType x)
{
    if (S->top == MaxSize - 1)
        return 0;
    S->data[++S->top] = x;
    return 1;
}

int Pop(SqStack *S, ElemType *x)
{
    if (S->top == -1)
        return 0;
    *x = S->data[S->top--];
    return 1;
}

void InitQueue(SqQueue *Q)
{

    //*Q->data = {0};
    memset(Q->data, 0, MaxSize);
    Q->front = Q->rear = 0; // 队空 front==rear
}

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

void toString(SqQueue Q)
{
    int i = Q.front;
    printf("\n当前队列：");
    while (i != Q.rear)
    {
        printf("<--%d", Q.data[i]);
        i = (i + 1) % MaxSize;
    }
}

void Reverse(SqQueue *Q)
{
    SqStack S;
    InitStack(&S);
    int rearflag = Q->rear;
    while (Q->front != rearflag)
    {
        int tmp;
        DeQueue(Q, &tmp);
        Push(&S, tmp);
    }
    while (S.top != -1)
    {
        int tmp;
        Pop(&S, &tmp);
        EnQueue(Q, tmp);
    }
}
int main()
{
    SqQueue Q;
    InitQueue(&Q);
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    toString(Q);
    Reverse(&Q);
    toString(Q);
    return 0;
}