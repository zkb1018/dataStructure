/*
 * @Descripttion:
 * @Author: zkb
 * @Date: 2023-01-19 14:51:39
 * @LastEditors: KB
 * @LastEditTime: 2023-01-20 23:31:22
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

StringList* prefixList(char *ch)
{
    int length = strlen(ch);
    StringList *pre=malloc(sizeof(StringList)*(length-1));
    for (int i = 0; i < length - 1; i++)
    {
        pre[i].ch = malloc(sizeof(char) * (i + 1));
        strncpy(pre[i].ch, ch, i + 1);
    }
    return pre;
}

StringList* suffixList(char *ch)
{
    int length = strlen(ch);
    StringList *suf=malloc(sizeof(StringList)*(length-1));
    for (int i = 0; i < length - 1; i++)
    {
        suf[i].ch = malloc(sizeof(char) * (length - 1 - i));
        strncpy(suf[i].ch, ch + i + 1, length - 1 - i);
    }
    return suf;
}

int maxPreSufLen(char *ch){
    int length = strlen(ch);
    if(length<=1){
        return 0;
    }
    StringList *pre= prefixList(ch);
    StringList *suf=suffixList(ch);
    StringList *same=malloc(sizeof(StringList)*(length-1));
    int sameIndex=0;
    for(int i=0;i<length-1;i++){
        for(int j=0;j<length-1;j++){
            if(strcmp((pre+i)->ch,(suf+j)->ch)==0){
                same[sameIndex].ch = malloc(sizeof(char) * strlen((pre+i)->ch));
                strcpy(same[sameIndex].ch,(pre+i)->ch);
                sameIndex++;
                break;
            }
        }
    }
    int maxLen=0;
    for(int i=0;i<sameIndex;i++){
        if(strlen(same[i].ch)>maxLen){
            maxLen=strlen(same[i].ch);
        }
    }
    return maxLen;
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
    //获取部分匹配值表
    int PM[T.length];
    for(int i=0;i<T.length;i++){
        char *ch=malloc(sizeof(char)*(i+1));
        strncpy(ch, T.ch, i+1);
        PM[i]=maxPreSufLen(ch);
    }
    
    int i=0,j=0;
    while (i < S.length && j < T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            //移动位数=已匹配字符数-对应部分匹配值
            i = i-j+(j-PM[j-1]);
            j = 0;
        }
    }
    if (j == T.length)
        return i - j;
    else
        return -1;

}
int main()
{
    char str1[] = "where are you from?";
    char str2[] = "from?";
    SString S1, S2;
    StrAssign(&S1, str1);
    StrAssign(&S2, str2);
  
    char test[]="ababa";
   

    char test1[] = "ababcabcacbab";
    char test2[] = "abcac";
    SString T1, T2;
    StrAssign(&T1, test1);
    StrAssign(&T2, test2);
    printf("(暴力匹配)位置：%d\n", violentIndex(T1, T2));
    printf("(KMP匹配)位置：%d\n", KMPIndex(T1,T2));
    // StringList *L=suffixList(test);
    return 0;
}