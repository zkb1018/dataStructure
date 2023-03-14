/*
 * @Descripttion:
 * @Author: KB
 * @Date: 2023-02-21 15:55:00
 * @LastEditors: KB
 * @LastEditTime: 2023-02-21 16:38:53
 */
#include <stdio.h>
#include "randArray.h"
void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
int main()
{
    int arr[10];
    randArray(10, 40, arr);
    printfArray(arr,10);
    bubbleSort(arr, 10);
    printfArray(arr,10);
    return 0;
}