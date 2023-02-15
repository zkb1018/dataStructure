/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-02-01 15:27:14
 * @LastEditors: KB
 * @LastEditTime: 2023-02-01 15:48:35
 */
/*
 * @lc app=leetcode.cn id=1109 lang=c
 *
 * [1109] 航班预订统计
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize){
    int* nums=malloc(sizeof(int)*n);
    memset(nums,0,sizeof(int)*n);
    *returnSize=n;
    for(int i=0;i<bookingsSize;i++){
        nums[bookings[i][0]-1]+=bookings[i][2];
        if(bookings[i][1]<n){
            nums[bookings[i][1]]-=bookings[i][2];
        }
    }
    for (int i = 1; i < n; i++)
    {
        nums[i]+=nums[i-1];
    }
    return nums;
}
// @lc code=end

