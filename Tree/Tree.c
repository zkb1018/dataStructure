/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-03-06 13:13:27
 * @LastEditors: KB
 * @LastEditTime: 2023-03-06 13:31:52
 */
#include<stdio.h>

#define MAX_TREE_SIZE 100
typedef int ElemType;

//双亲表示法
typedef struct 
{
    ElemType data;
    int parent;
}PTNode;
typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    int n;//结点数
}PTree;

//孩子兄弟表示法
typedef struct CSNode
{
    ElemType data;
    struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;



int main(){
    return 0;
}