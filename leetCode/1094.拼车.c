/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-02-01 16:05:15
 * @LastEditors: KB
 * @LastEditTime: 2023-02-01 16:21:23
 */
/*
 * @lc app=leetcode.cn id=1094 lang=c
 *
 * [1094] 拼车
 */

// @lc code=start


bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    int* nums=malloc(sizeof(int)*1001);
    memset(nums,0,sizeof(int)*1001);
    for(int i=0;i<tripsSize;i++){
        nums[trips[i][1]]+=trips[i][0];
        nums[trips[i][2]]-=trips[i][0];
    }
    int cur=0;
    for(int i=0;i<1001;i++){
        cur+=nums[i];
        if(cur>capacity){
            return false;
        }
    }
    return true;
}
// @lc code=end

