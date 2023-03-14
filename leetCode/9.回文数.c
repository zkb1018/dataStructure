/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-03-08 15:46:24
 * @LastEditors: KB
 * @LastEditTime: 2023-03-08 15:54:51
 */
/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start
bool isPalindrome(int x){
    if(x<0){
        return false;
    }
    else{
        int y=x;
        int tmp=0;
        while (x)
        {   
            if(tmp>__INT32_MAX__/10){
                return false;
            }
            tmp=tmp*10+x%10;
            x/=10;
        }
        if(y==tmp){
            return true;
        }
        else return false;
        
    }
}
// @lc code=end

