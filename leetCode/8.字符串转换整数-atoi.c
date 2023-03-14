/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-03-03 17:01:28
 * @LastEditors: KB
 * @LastEditTime: 2023-03-06 10:47:13
 */
/*
 * @lc app=leetcode.cn id=8 lang=c
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include<stdio.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
int myAtoi(char * s){
    int i=0;
    int result=0;
    int flag=1;
    int isChangeFlag=0;
    int overFlag=0;
    while (s[i]!='\0')
    {
        if(s[i]==32){
            i++;
            continue;
        }
        else if(s[i]==45&&!isChangeFlag){
            flag=-1;
            isChangeFlag=1;
            i++;
            continue;
        }
        else if(s[i]=='+'&&!isChangeFlag){
            flag=1;
            isChangeFlag=1;
            i++;
            continue;
        }
        else if(s[i]<48||s[i]>57){
            break;
        }else{
            if(result==0&&s[i]==48){
                i++;
            }
            else{
                if(result<INT_MIN/10||result>INT_MAX/10){
                    overFlag=1;
                    break;
                };
                result=result*10+(s[i]-48);
                i++;
            }
        }
    }
    if(overFlag&&flag==1){
        return INT_MAX;
    }
    else if(overFlag&&flag==-1){
        return INT_MIN;
    }
    return flag*result;
}
// int main(){
//     char ch='-';
//     //printf("%d",ch);
//    printf("%d",myAtoi("-91283472332"));
//    //printf("%d",__INT32_MAX__);
// }
// @lc code=end

