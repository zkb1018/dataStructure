/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-03-08 15:55:23
 * @LastEditors: KB
 * @LastEditTime: 2023-03-09 17:28:21
 */
/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
bool isMatch(char * s, char * p){
    if(p[0]=='\0')  return false;
    int i=0;
    while (p[i]!='\0')
    {
        if(p[i]!='.'&&p[i]!='*'&&p[i]!=s[i]){
            return false;
        }
    }
    
}
// @lc code=end

