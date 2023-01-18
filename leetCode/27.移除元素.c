/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-01-18 11:48:18
 * @LastEditors: KB
 * @LastEditTime: 2023-01-18 11:54:03
 */
/*
 * @lc app=leetcode.cn id=27 lang=c
 *
 * [27] 移除元素
 */

// @lc code=start


int removeElement(int* nums, int numsSize, int val){
    int slow=0,fast=0;
    while (fast<numsSize)
    {
        if(nums[fast]!=val){
            nums[slow]=nums[fast];
            slow++;
        }
        fast++;
    }
    return slow;
}
// @lc code=end

