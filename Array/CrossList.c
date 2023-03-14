/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-02-15 21:13:40
 * @LastEditors: KB
 * @LastEditTime: 2023-02-15 22:56:36
 */
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct OLNode{
    int i,j;
    ElemType e;
    struct OLNode *right,*down;
}OLNode,*OLink;

typedef struct
{
    OLink *rhead,*chead;
    int mu,nu,tu;
}CrossList;

void CreateSMatrix_OL(CrossList *M,int row,int col,int mtu){
    if(M) free(M);
    M->mu=row;
    M->nu=col;
    M->tu=mtu;
    if(!(M->rhead=(OLink*)malloc((row+1)*sizeof(OLink)))) return;
    // if(!(N->))
}