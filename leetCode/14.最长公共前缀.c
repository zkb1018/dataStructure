/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-03-09 17:17:27
 * @LastEditors: KB
 * @LastEditTime: 2023-03-10 14:44:02
 */
/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include<stdio.h>
#include<stdlib.h>
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0) return "";
    char *ans=strs[0];
    for(int i=1;i<strsSize;i++){
        int j=0;
        for(;j<strlen(ans)&&j<strlen(strs[i]);j++){
            if(ans[j]!=strs[i][j]) break;
        }
        strncpy(ans,strs[i],j);
        ans[j]='\0';
        if(ans[0]=='\0'){
            return "";
        }
    }
    return ans;
}
// int main(){
//     return 0;
// }
// @lc code=end

