/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-02-26 09:45:31
 * @LastEditors: KB
 * @LastEditTime: 2023-02-26 14:15:42
 */
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct ThreadNode
{
    ElemType data;
    int ltag,rtag;
    struct ThreadNode *lchild,*rchild;
}ThreadNode,*ThreadTree;

ThreadTree testData(){
    ThreadTree T=(ThreadNode*)malloc(sizeof(ThreadNode));
    T->data=1;
    T->lchild=(ThreadNode*)malloc(sizeof(ThreadNode));
    T->lchild->data=2;
    ThreadNode *n=(ThreadNode*)malloc(sizeof(ThreadNode));
    n->data=4;
    T->lchild->rchild=n;
    T->rchild=(ThreadNode*)malloc(sizeof(ThreadNode));
    T->rchild->data=3;
    return T;
    
}

void destroy(ThreadTree T)
{
    if (T->lchild)
    {
        destroy(T->lchild);
    }
    if (T->rchild)
    {
        destroy(T->rchild);
    }
    free(T);
}


ThreadTree pre;
void inThread(ThreadTree p){
    if(p){
        inThread(p->lchild);
        if(!p->lchild){
            p->lchild=pre;
            p->ltag=1;
        }
        
        if(!pre->rchild){
            pre->rchild=p;
            pre->rtag=1;
        }
        pre=p;
        inThread(p->rchild);
    }
}
int main(){
    ThreadTree T=testData();
    pre=(ThreadNode*)malloc(sizeof(ThreadNode));
    
    inThread(T);
    destroy(T);
    free(pre);
    return 0;
}