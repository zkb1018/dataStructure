/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-01-18 12:52:53
 * @LastEditors: KB
 * @LastEditTime: 2023-01-18 12:54:50
 */
/*
 * @lc app=leetcode.cn id=344 lang=c
 *
 * [344] 反转字符串
 */

// @lc code=start


void reverseString(char* s, int sSize){
    int left=0,right=sSize-1;
    while(left<right){
        int tmp=s[right];
        s[right]=s[left];
        s[left]=tmp;
        left++;
        right--;
    }
}
// @lc code=end

