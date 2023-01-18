
/*
 * @lc app=leetcode.cn id=283 lang=c
 *
 * [283] 移动零
 */

// @lc code=start


void moveZeroes(int* nums, int numsSize){
    int slow=0,fast=0;
    while(fast<numsSize){
        if(nums[fast]!=0){
            nums[slow]=nums[fast];
            slow++;
        }
        fast++;
    }
    while(slow<numsSize){
        nums[slow]=0;
        slow++;
    }

}
// @lc code=end

