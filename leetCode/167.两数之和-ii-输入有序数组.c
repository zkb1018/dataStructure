/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-01-18 12:38:24
 * @LastEditors: KB
 * @LastEditTime: 2023-01-18 12:50:02
 */
/*
 * @lc app=leetcode.cn id=167 lang=c
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int left=0,right=numbersSize-1;
    *returnSize=2;
    int *result=(int*)malloc(sizeof(int)*2);
    while(left<right){
        if(numbers[left]+numbers[right]==target){
            result[0]=left+1;
            result[1]=right+1;
            return result;
        }
        else if(numbers[left]+numbers[right]<target){
            left++;
        }
        else{
            right--;
        }
    }
    result[0]=-1;
    result[1]=-1;
    return result;
}
// @lc code=end

