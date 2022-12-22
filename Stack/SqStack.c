
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
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

void toString(SqStack S)
{
    for (int j = S.top; j > -1; j--)
    {
        printf("|%4d|\n", S.data[j]);
    }
}

void GetTop(SqStack S)
{
    if (S.top == -1)
        return;
    printf("Top:%d\n", S.data[S.top]);
}
int main()
{
    SqStack S;
    InitStack(&S);
    Push(&S, 4);
    Push(&S, 14);
    Push(&S, 43);
    Push(&S, 42);
    Push(&S, 11);
    int tmp;
    Pop(&S, &tmp);
    toString(S);
    GetTop(S);
    return 0;
}