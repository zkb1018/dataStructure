
/*
 * @Descripttion:稀疏矩阵 
 * @Author: KB
 * @Date: 2023-02-12 19:48:53
 * @LastEditors: KB
 * @LastEditTime: 2023-02-12 21:19:24
 */
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1200
typedef int ElemType;
typedef struct
{
    int i,j;
    ElemType e;
}Triple;
typedef struct 
{
    Triple data[MAXSIZE+1];//data[0]未用
    int mu,nu,tu;//行数 列数 非零元数
}TSMatrix;

void toString(TSMatrix M){
    if(M.tu==0) return;
    else{
        printf("===================\n");
        printf("%*s",4,"");
        printf("i");
        printf("%*s",4,"");
        printf("j");
        printf("%*s",4,"");
        printf("v\n");
        printf("-------------------\n");

        for(int i=1;i<=M.tu;i++){
            printf("%5d%5d%5d\n",M.data[i].i,M.data[i].j,M.data[i].e);
        }
        printf("===================\n");
    }
}

void initTestData(TSMatrix *M,int n,int (*arr)[n]){
    M->mu=n;
    M->nu=n;
    M->tu=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                M->tu++;
                M->data[M->tu].i=i+1;
                M->data[M->tu].j=j+1;
                M->data[M->tu].e=arr[i][j];
            }
        }
    }
}

/**
 * @msg:三元组稀疏矩阵普通转置   
 * @param {TSMatrix} M
 * @param {TSMatrix} *T
 * @return {*}
 */
void TransposeSMatrix(TSMatrix M,TSMatrix *T){
    T->mu=M.mu;
    T->nu=M.nu;
    T->tu=M.tu;
    if(T->tu){
        int q=1;
        for(int row=1;row<=M.nu;++row){
            for(int p=1;p<=M.tu;++p){
                if(M.data[p].j==row){
                    T->data[q].i=M.data[p].j;
                    T->data[q].j=M.data[p].i;
                    T->data[q].e=M.data[p].e;
                    ++q;
                }
            }
        }
    }
}

/**
 * @msg:快速转置 
 * 
 *  cpot[1]=1;
 *  cpot[col]=cpot[col-1]+num[col-1] ;
 *  num[col]表示矩阵M中第col列中非零元素个数
 *  cpot[col]指示M中第col列的第一个非零元在b.data的位置
 * 
 * @param {TSMatrix} M
 * @param {TSMatrix} *T
 * @return {*}
 */
void FastTransposeSMatrix(TSMatrix M,TSMatrix *T){
    T->mu=M.mu;
    T->nu=M.nu;
    T->tu=M.tu;
    int num[M.nu+1];
    int cpot[M.nu+1];
    if(T->tu){
        for(int col=1;col<=M.nu;++col) num[col]=0;
        for(int t=1;t<=M.tu;++t) ++num[M.data[t].j];
        cpot[1]=1;
        for(int col=2;col<=M.nu;++col){
            cpot[col]=cpot[col-1]+num[col-1];
        }
        for(int p=1;p<=M.tu;++p){
            int col= M.data[p].j;
            int q=cpot[col];
            T->data[q].i=M.data[p].j;
            T->data[q].j=M.data[p].i;
            T->data[q].e=M.data[p].e;
            ++cpot[col];
        }
    }
}
int main(){
    int arr[6][6]={
        0,12,9,0,0,0,
        0,0,0,0,0,0,
        -3,0,0,0,0,14,
        0,0,24,0,0,0,
        0,18,0,0,0,0,
        15,0,0,-7,0,0
    };
    TSMatrix TM;
    TSMatrix T;
    initTestData(&TM,6,arr);
    toString(TM);
    // TransposeSMatrix(TM,&T);
    FastTransposeSMatrix(TM,&T);
    toString(T);                        
    return 0;
}