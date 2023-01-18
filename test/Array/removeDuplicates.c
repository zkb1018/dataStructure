/*
 * @Descripttion: 数组去重
 * @Author: KB
 * @Date: 2023-01-18 09:46:57
 * @LastEditors: KB
 * @LastEditTime: 2023-01-18 10:49:46
 */
#include <stdio.h>
#include<stdlib.h>
/**
 * @msg: 返回不重复元素个数n 并将其放在原数组前n位
 * @param {int} *nums
 * @param {int} length
 * @return {*}
 */
int removeDuplicates(int *nums,int length)
{
    int slow = 0, fast = 0;
    while (fast < length)
    {
        if (nums[slow] != nums[fast])
        {
            slow++;
            nums[slow] = nums[fast];
        }
        fast++;
    }
    return slow+1;
}
int main()
{
    int num[] = {1, 1, 3, 4, 4, 4, 6, 7};
    int length=removeDuplicates(num,8);
    for(int i=0;i<length;i++){
        printf("%d ",num[i]);
    }
    return 0;
}
