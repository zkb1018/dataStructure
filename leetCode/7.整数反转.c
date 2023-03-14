/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-03-03 15:49:22
 * @LastEditors: KB
 * @LastEditTime: 2023-03-03 16:55:13
 */
/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start


int reverse(int x){
    int flag=1;
    if(x==0)return 0;
    // else if(x<0){
    //     flag=-1;
    // }
    int result=0;

    while (x)
    {
        if(result<INT_MIN/10||result>INT_MAX/10){
            return 0;
        };
        int rest=x%10;
        x=x/10;
        result=result*10+rest;
    }
    return flag*result;
    
    
}
// @lc code=end

