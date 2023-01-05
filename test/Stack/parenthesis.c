/*
 * @Descripttion:检验输入括号字符串的合法性
 * @Author: zkb
 * @Date: 2022-12-29 16:01:59
 * @LastEditors: zkb
 * @LastEditTime: 2023-01-04 14:11:30
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

int Pop(SqStack *S)
{
    if (S->top == -1)
        return 0;
    S->top--;
    return 1;
}
ElemType GetTop(SqStack S)
{
    if (S.top == -1)
        return '#';
    return S.data[S.top];
}
void check(char *l)
{
    SqStack S;
    InitStack(&S);
    while (*l != '\0')
    {
        char expect;
        switch (GetTop(S))
        {
        case '#':
            break;
        case '{':
            expect = '}';
            break;
        case '[':
            expect = ']';
            break;
        case '(':
            expect = ')';
            break;
        default:
            printf("不合法\n");
            return;
        }
        if (expect == *l)
        {
            Pop(&S);
            l++;
        }
        else
        {
            Push(&S, *l);
            l++;
        }
    }
    if (GetTop(S) != '#')
    {
        printf("不合法\n");
    }
    else
    {
        printf("合法\n");
    }
}
int main()
{
    char list[] = "[{]]";
    check(list);
    return 0;
}