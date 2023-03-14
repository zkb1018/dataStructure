/*
 * @Descripttion: 快速排序
 * @Author: KB
 * @Date: 2023-03-01 14:46:06
 * @LastEditors: KB
 * @LastEditTime: 2023-03-01 15:01:14
 */
#include <stdio.h>
#include "randArray.h"
int sortOnce(int *arr, int left, int right)
{
    if (left >= right)
        return left;
    int pivos = arr[left];
    while (left < right)
    {
        while (arr[right] > pivos && left < right)
        {
            right--;
        }
        arr[left] = arr[right];
        while (arr[left] <= pivos && left < right)
        {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left]=pivos;
    return left;
}
void fastSort(int *arr, int left,int right)
{
    if(left<right){
        int pivos=sortOnce(arr,left,right);
        fastSort(arr,left,pivos-1);
        fastSort(arr,pivos+1,right);
    }
}
int main()
{
    int arr[10];
    randArray(10, 40, arr);
    printfArray(arr, 10);
    fastSort(arr, 0,9);
    printfArray(arr, 10);
    return 0;
}