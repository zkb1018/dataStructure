/*
 * @Descripttion:
 * @Author: KB
 * @Date: 2023-02-16 12:24:28
 * @LastEditors: KB
 * @LastEditTime: 2023-02-26 09:49:39
 */
#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"

BiTree testData(){
    BiTree T=(BiTNode*)malloc(sizeof(BiTNode));
    T->data=1;
    T->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    T->lchild->data=2;
    BiTNode *n=(BiTNode*)malloc(sizeof(BiTNode));
    n->data=4;
    T->lchild->rchild=n;
    T->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    T->rchild->data=3;
    return T;
    
}

void destroy(BiTree T)
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

int main()
{
   
    
    BiTree T= testData();
    printf("\n********递归遍历*******");
    printf("\n先序遍历：");
    preOrder(T);
    printf("\n中序遍历：");
    inOrder(T);
    printf("\n后序遍历：");
    subOrder(T);
    printf("\n********非递归遍历*******");
    printf("\n先序遍历：");
    preOrderByStack(T);
    printf("中序遍历：");
    inOrderByStack(T);
    printf("后序遍历：");
    subOrderByStack(T);
    printf("\n层次遍历：");
    levelOrder(T);
    printf("\n树高度：%d\n",maxHeight(T));
    printBiTree(T);
    destroy(T);

    return 0;
}
