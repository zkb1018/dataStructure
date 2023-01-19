/*
 * @Descripttion:
 * @Author: zkb
 * @Date: 2023-01-19 14:51:39
 * @LastEditors: zkb
 * @LastEditTime: 2023-01-19 16:23:14
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 255
typedef struct
{
    char ch[MAXLEN];
    int length;
} SString;
typedef struct
{
    char *ch;
} StringList;

void StrAssign(SString *S, char *ch)
{
    int i = 0;
    while (ch[i] != '\0')
    {
        S->ch[i] = ch[i];
        i++;
    }
    S->length = i;
}

void prefixList(char *ch)
{
    int length = strlen(ch);
    StringList strList[length - 1];
    for (int i = 0; i < length - 1; i++)
    {
        strList[i].ch = malloc(sizeof(char) * (i + 1));
        strncpy(strList[i].ch, ch, i + 1);
    }
}

void suffixList(char *ch)
{
    int length = strlen(ch);
    StringList strList[length - 1];
    for (int i = 0; i < length - 1; i++)
    {
        strList[i].ch = malloc(sizeof(char) * (length - 1 - i));
        strncpy(strList[i].ch, ch + i + 1, length - 1 - i);
    }
}
/**
 * @msg: 暴力匹配
 * @param {SString} S
 * @param {SString} T
 * @return {*}
 */
int violentIndex(SString S, SString T)
{
    int i = 0, j = 0;
    while (i < S.length && j < T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == T.length)
        return i - j;
    else
        return -1;
}

/**
 * @msg: 使用KMP算法改进暴力匹配
 * @param {SString} S
 * @param {SString} T
 * @return {*}
 */
int KMPIndex(SString S, SString T)
{
}
int main()
{
    char str1[] = "where are you from?";
    char str2[] = "from?";
    SString S1, S2;
    StrAssign(&S1, str1);
    StrAssign(&S2, str2);
    printf("(暴力匹配)位置：%d\n", violentIndex(S1, S2));
    suffixList(S2.ch);
    return 0;
}