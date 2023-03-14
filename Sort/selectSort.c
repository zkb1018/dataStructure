/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-02-23 09:41:04
 * @LastEditors: KB
 * @LastEditTime: 2023-02-23 09:45:55
 */
#include<stdio.h>
#include"randArray.h"

void selectSort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int tmp=arr[j];
                arr[j]=arr[i];
                arr[i]=tmp;
            }
        }
    }
}

int main(){
    int arr[10];
    randArray(10, 40, arr);
    printfArray(arr,10);
    selectSort(arr, 10);
    printfArray(arr,10);
    return 0;
}