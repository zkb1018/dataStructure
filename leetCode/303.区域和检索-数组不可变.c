/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-01-20 20:53:53
 * @LastEditors: KB
 * @LastEditTime: 2023-01-20 21:32:35
 */
/*
 * @lc app=leetcode.cn id=303 lang=c
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start



typedef struct {
    int *Sums;//前缀和
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *na=(NumArray*)malloc(sizeof(NumArray));
    na->Sums=malloc(sizeof(int)*(numsSize+1));
    na->Sums[0]=0;
    for(int i=0;i<numsSize;i++){
        na->Sums[i+1]=na->Sums[i]+nums[i];
    }
    return na;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->Sums[right+1]-obj->Sums[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->Sums);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/
// @lc code=end

