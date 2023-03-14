/*
 * @Descripttion:
 * @Author: KB
 * @Date: 2023-03-01 15:05:30
 * @LastEditors: KB
 * @LastEditTime: 2023-03-14 10:03:40
 */
#include <stdio.h>
#include "randArray.h"
void insertSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int cur = arr[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > cur)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = cur;
    }
}
void binaryInsertSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            int cur = arr[i];
            int left = 0;
            int right = i - 1;
            int mid;
            while (left <= right)
            {
                mid = (left + right) / 2;
                if (cur > arr[mid])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            for (int j = i; j > left; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[left] = cur;
        }
    }
}
int main()
{
    int arr[10];
    randArray(10, 40, arr);
    printfArray(arr, 10);
    // insertSort(arr, 10);
    binaryInsertSort(arr, 10);
    printfArray(arr, 10);
    return 0;
}