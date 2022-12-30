/*
 * @Descripttion:检验输入括号字符串的合法性
 * @Author: zkb
 * @Date: 2022-12-29 16:01:59
 * @LastEditors: zkb
 * @LastEditTime: 2022-12-29 16:11:56
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int top;
} SqStack;
void InitStack(SqStack *S)
{
    S->top = -1;
}

int StackEmpty(SqStack S)
{
    if (S.top == -1)
    {
        return 1;
    }
    else
        return 0;
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
