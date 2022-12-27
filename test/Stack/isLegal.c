/*
 * @Descripttion: I、O分别表示入栈和出栈 判断又IO组成的序列是否合法
 * @Author: zkb
 * @Date: 2022-12-27 10:31:16
 * @LastEditors: zkb
 * @LastEditTime: 2022-12-27 10:41:27
 */
#include <stdio.h>
void isLegal(char *list)
{
    int i = 0, o = 0;
    int length = sizeof(list) / sizeof(char);
    for (int j = 0; j < length; j++)
    {
        if (o > i)
        {
            printf("不合法\n");
            return;
        }
        if (list[j] == 'I')
        {
            i++;
        }
        if (list[j] == 'O')
        {
            o++;
        }
    }
    printf("合法\n");
}
int main()
{
    char list1[6] = {'I', 'I', 'O', 'O', 'I', 'O'};
    char list2[6] = {'I', 'O', 'O', 'O', 'I', 'O'};
    isLegal(list1);
    isLegal(list2);
    return 0;
}