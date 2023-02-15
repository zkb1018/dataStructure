/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-02-12 21:18:55
 * @LastEditors: KB
 * @LastEditTime: 2023-02-15 21:06:58
 */
#include<stdio.h>
#define MAXSIZE 1200
#define MAXRC 20

typedef int ElemType;
typedef struct
{
    int i,j;
    ElemType e;
}Triple;
typedef struct
{
    Triple data[MAXSIZE+1];
    int rpos[MAXRC+1];//各行第一个非零元素的位置表
    int mu,nu,tu;
}RLSMatrix;


void toString(RLSMatrix M){
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
        for(int i=1;i<=M.mu;i++){
            printf("%d\n",M.rpos[i]);
        }
        
    }
}

void MultSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix *Q){
    if(M.nu!=N.mu) return;
    Q->mu=M.mu;
    Q->nu=N.nu;
    Q->tu=0;
    if(M.tu*N.tu!=0){
        for(int arow=1;arow<=M.mu;++arow){
            int ctemp[10]={0};
            Q->rpos[arow]=Q->tu+1;
            int tp,t;
            if(arow<M.mu)
                tp=M.rpos[arow+1];
            else{
                tp=M.tu+1;
            }
            for (int p = M.rpos[arow]; p < tp; p++)
            {
                int brow=M.data[p].j;
                if(brow<N.mu) t=N.rpos[brow+1];
                else{
                    t=N.tu+1;
                }
                for(int q=N.rpos[brow];q<t;++q){
                    int ccol=N.data[q].j;
                    ctemp[ccol]+=M.data[p].e*N.data[q].e;
                }
            }
            for(int ccol=1;ccol<=Q->nu;++ccol){
                if(ctemp[ccol]){
                    if(++Q->tu>MAXSIZE) return;
                    Q->data[Q->tu].i=arow;
                    Q->data[Q->tu].j=ccol;
                    Q->data[Q->tu].e=ctemp[ccol];
                }
            }
            
        }
    }
}

void InitRLSMatrix(RLSMatrix *M,int row,int col,int arr[row][col]){
    M->mu=row;
    M->nu=col;
    int mtu=0;
    for(int i=0;i<row;++i){
        int isFirst=1;//是否为该行第一个非零元素
        for(int j=0;j<col;++j){
            if(arr[i][j]){
                mtu++;
                if(isFirst){
                    M->rpos[i+1]=mtu;
                    isFirst=0;
                }
                M->data[mtu].i=i+1;
                M->data[mtu].j=j+1;
                M->data[mtu].e=arr[i][j];
            }
        }
        
    }
    M->tu=mtu;
}
int main(){
    int m[3][4]={
        3,0,0,5,
        0,-1,0,0,
        2,0,0,0
    };
    int n[4][2]={
        0,2,
        1,0,
        -2,4,
        0,0
    };
    RLSMatrix M,N,Q;
    InitRLSMatrix(&M,3,4,m);
    InitRLSMatrix(&N,4,2,n);
    toString(M);
    toString(N);
    MultSMatrix(M,N,&Q);
    toString(Q);
    return 0;
}