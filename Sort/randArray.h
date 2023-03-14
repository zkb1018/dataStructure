/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-02-21 15:48:48
 * @LastEditors: KB
 * @LastEditTime: 2023-02-21 16:39:37
 */
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

void randArray(int n,int max,int *arr){
    srand((unsigned)time(NULL));
    
    //int arr[n]={0};
    for(int i=0;i<n;i++){
        arr[i]=rand()%max;
    }  
}
void printfArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}