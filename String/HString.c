/*
 * @Descripttion:
 * @Author: zkb
 * @Date: 2023-01-19 10:18:17
 * @LastEditors: zkb
 * @LastEditTime: 2023-01-19 12:45:59
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char *ch;
    int length;
} HString;

/**
 * @msg: 将串S赋值为ch
 * @param {HString*} S
 * @param {char} *ch
 * @return {*}
 */
void StrAssign(HString *S, char *ch)
{
    S->ch = ch;
    int i = 0;
    while (ch[i] != '\0')
    {
        i++;
    }
    S->length = i;
}

/**
 * @msg: 由串S复制得到串T
 * @param {HString} *T
 * @param {HString} S
 * @return {*}
 */
void StrCopy(HString *T, HString S)
{
    T->ch = malloc(sizeof(char) * S.length);
    for (int i = 0; i < S.length; i++)
    {
        T->ch[i] = S.ch[i];
    }
    T->length = S.length;
}

int StrEmpty(HString S)
{
    if (S.length == 0)
        return 1;
    else
        return 0;
}

int StrLength(HString S)
{
    return S.length;
}

/**
 * @msg: 比较S T长度 大于返回1 相等返回0 小于返回-1
 * @param {HString} S
 * @param {HString} T
 * @return {*}
 */
int StrCompare(HString S, HString T)
{
    if (StrLength(S) == StrLength(T))
        return 0;
    else if (StrLength(S) > StrLength(T))
        return 1;
    else
        return -1;
}

/**
 * @msg: 求S从位置pos开始长度为len的子串
 * @param {HString} *sub
 * @param {HString} S
 * @param {int} pos
 * @param {int} len
 * @return {*}
 */
void SubString(HString *sub, HString S, int pos, int len)
{
    if (pos + len > S.length)
    {
        printf("长度不符合要求！\n");
        return;
    }
    char *ch = malloc(sizeof(char) * len);
    for (int i = 0; i < pos + len; i++)
    {
        if (i < pos)
        {
            S.ch++;
        }
        else
        {
            ch[i - pos] = S.ch[i - pos];
        }
    }
    ch[len] = '\0';
    sub->ch = ch;
    sub->length = len;
}

/**
 * @msg: 用T返回S1 S2合成的新串
 * @param {HString} *T
 * @param {HString} S1
 * @param {HString} S2
 * @return {*}
 */
void Concat(HString *T, HString S1, HString S2)
{
    T->ch = malloc(sizeof(char) * (S1.length + S2.length));
    int i = 0;
    while (i < S1.length)
    {
        T->ch[i] = S1.ch[i];
        i++;
    }
    i = 0;
    while (i < S2.length)
    {
        T->ch[S1.length + i] = S2.ch[i];
        i++;
    }
    T->ch[S1.length + i] = '\0';
    T->length = S1.length + S2.length;
}

/**
 * @msg: 主串S中是否存在与T相同的字串 有则返回字串初始位置，否则返回-1
 * @param {HString} S
 * @param {HString} T
 * @return {*}
 */
int index(HString S, HString T)
{
    int i = 0;
    int lenS = S.length;
    int lenT = T.length;
    if (lenT > lenS)
        return -1;
    while (i <= lenS - lenT)
    {
        int j = 0;
        for (j = 0; j < lenT; j++)
        {
            if (S.ch[i + j] != T.ch[j])
                break;
        }
        if (j == lenT)
        {
            return i;
        }
        i++;
    }
    return -1;
}

void ClearString(HString *S)
{
    S->ch = '\0';
    S->length = 0;
}

void DestroyString(HString *S)
{
    free(S->ch);
    S = NULL;
}
int main()
{
    char s[] = "hello world";
    HString S;
    StrAssign(&S, s);

    HString sub;
    SubString(&sub, S, 3, 3);

    char s1[] = " KB";
    HString S1;
    StrAssign(&S1, s1);
    HString T;
    Concat(&T, S, S1);

    HString test;
    StrAssign(&test, "wol");
    printf("%d\n", index(S, test));

    ClearString(&test);
    DestroyString(&test);
    return 0;
}
