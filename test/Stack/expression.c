/*
 * @Descripttion: 中缀表达式转后缀表达式 利用栈计算结果
 * @Author: zkb
 * @Date: 2023-01-04 14:25:18
 * @LastEditors: zkb
 * @LastEditTime: 2023-01-05 17:21:03
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 20
typedef struct
{
    char data[MaxSize];
    int top;
} SqStack;
typedef struct
{
    int data[MaxSize];
    int top;
} IntSqStack;
int priority(char opt)
{
    switch (opt)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;

    default:
        return -1;
    }
}
char GetTop(SqStack S)
{
    if (S.top == -1)
        return '#';
    else
        return S.data[S.top];
}
void InitStack(SqStack *S)
{
    S->top = -1;
}
int Pop(SqStack *S, char *x)
{
    if (S->top == -1)
        return 0;
    else
    {
        *x = S->data[S->top--];
        return 1;
    }
}
int Push(SqStack *S, char x)
{
    if (S->top >= MaxSize)
        return 0;
    else
    {
        S->data[++S->top] = x;
        return 1;
    }
}

void IntInitStack(IntSqStack *S)
{
    S->top = -1;
}
int IntPop(IntSqStack *S, int *x)
{
    if (S->top == -1)
        return 0;
    else
    {
        *x = S->data[S->top--];
        return 1;
    }
}
int IntPush(IntSqStack *S, int x)
{
    if (S->top >= MaxSize)
        return 0;
    else
    {
        S->data[++S->top] = x;
        return 1;
    }
}

/**
 * @msg: 中缀表达式转后缀表达式
 * @param {char} *e
 * @param {char} *res 结果
 * @return {*}
 */
void *transform(char *e, char *res)
{
    SqStack S;
    InitStack(&S);
    while (*e != '\0')
    {
        if (48 <= *e && *e <= 57)
        {
            *res = *e;
            res++;
            e++;
        }
        else
        {
            if (*e == '(')
            {
                Push(&S, *e);
                e++;
            }
            if (*e == ')')
            {
                while (S.data[S.top] != '(')
                {
                    char pop;
                    Pop(&S, &pop);
                    *res = pop;
                    res++;
                }
                char pop;
                Pop(&S, &pop);
                e++;
            }
            if (priority(*e) != -1)
            {
                if (S.top == -1)
                {
                    Push(&S, *e);
                    e++;
                }
                else
                {

                    char stackTop = GetTop(S);
                    if (priority(stackTop) < priority(*e))
                    {
                        Push(&S, *e);
                        e++;
                    }
                    else
                    {
                        char pop;
                        Pop(&S, &pop);
                        *res = pop;
                        res++;
                    }
                }
            }
        }
    }
    while (S.top != -1)
    {
        char pop;
        Pop(&S, &pop);
        *res = pop;
        res++;
    }

    *res = '\0';
}

/**
 * @msg: 由后缀表达式计算结果
 * @param {char} *res
 * @return {*}
 */
int calculate(char *res)
{
    IntSqStack S;
    IntInitStack(&S);
    while (*res != '\0')
    {
        if (*res >= 48 && *res <= 57)
        {
            int tmp = *res - '0';
            IntPush(&S, tmp);
            res++;
        }
        else
        {
            int _opt1, _opt2;
            IntPop(&S, &_opt1);
            IntPop(&S, &_opt2);
            int result;
            switch (*res)
            {
            case '+':
                result = _opt2 + _opt1;
                break;
            case '-':
                result = _opt2 - _opt1;
                break;
            case '*':
                result = _opt2 * _opt1;
                break;
            case '/':
                result = _opt2 / _opt1;
                break;
            default:
                break;
            }
            IntPush(&S, result);
            res++;
        }
    }
    return S.data[S.top];
}
int main()
{
    char exp[] = "9+(3-1)*3+8/2";
    char res[20] = {};
    transform(exp, &res);
    printf("%s=%d", exp, calculate(res));
    return 0;
}