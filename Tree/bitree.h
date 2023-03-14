/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-02-16 12:53:56
 * @LastEditors: KB
 * @LastEditTime: 2023-02-26 09:22:33
 */
#include<stdio.h>

#include<stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef BiTree ElemType1;
typedef struct
{
    ElemType1 data[MaxSize];
    int front, rear;
} SqQueue;
void InitQueue(SqQueue *Q)
{

    //*Q->data = {0};
    Q->front = Q->rear = 0; // 队空 front==rear
}

/**
 * @msg: 入队
 * @param {SqQueue} *Q
 * @param {ElemType1} x
 * @return {*}
 */
int EnQueue(SqQueue *Q, ElemType1 x)
{
    if ((Q->rear + 1) % MaxSize == Q->front)
    {
        printf("队满！\n");
        return 0;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize;
    return 1;
}
int IsEmpty(SqQueue Q){
    if (Q.front == Q.rear)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int DeQueue(SqQueue *Q, ElemType1 *x)
{
    if (Q->front == Q->rear)
    {
        printf("队空!\n");
        return 0;
    }
    *x = Q->data[Q->front];
    Q->data[Q->front] = 0;
    Q->front = (Q->front + 1) % MaxSize;
    return 1;
}

typedef struct
{
    ElemType1 data[MaxSize];
    int top;
} SqStack;
void InitStack(SqStack *S)
{
    S->top = -1;
}
int StackEmpty(SqStack S)
{
    if (S.top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int Push(SqStack *S, ElemType1 x)
{
    if (S->top == MaxSize - 1)
        return 0;
    S->data[++S->top] = x;
    return 1;
}
int Pop(SqStack *S, ElemType1 *x)
{
    if (S->top == -1)
        return 0;
    *x = S->data[S->top--];
    return 1;
}
void GetTop(SqStack S,ElemType1 *x)
{
    if (S.top == -1)
        *x=NULL;
    *x=S.data[S.top];
}
/**
 * @msg: 求二叉树高度
 * @param {BiTree} T
 * @return {*}
 */
int maxHeight(BiTree T){
    if(T==NULL){
        return 0;
    }
    if(T->lchild==NULL&&T->rchild==NULL){
        return 1;
    }
    int lm=maxHeight(T->lchild);
    int rm=maxHeight(T->rchild);
    return lm>rm?lm+1:rm+1;

}
/*
    递归实现遍历
*/
void preOrder(BiTree T){
    if(T){
        printf("%d ",T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}
void inOrder(BiTree T){
    if(T){
        inOrder(T->lchild);
        printf("%d ",T->data);
        inOrder(T->rchild);
    }
}
void subOrder(BiTree T){
    if(T){
        subOrder(T->lchild);
        subOrder(T->rchild);
        printf("%d ",T->data);
    }
}
/*
    非递归实现遍历(栈)
*/
void preOrderByStack(BiTree T){
    SqStack s;
    InitStack(&s);
    BiTree p=T;
    while (p||!StackEmpty(s))
    {
        if(p){
            printf("%d ",p->data);
            Push(&s,p);
            p=p->lchild;
        }
        else{
            Pop(&s,&p);
            p=p->rchild;
        }
    }
    printf("\n");
}
void inOrderByStack(BiTree T){
    SqStack s;
    InitStack(&s);
    BiTree p=T;
    while (p||!StackEmpty(s))
    {
        if(p){
            Push(&s,p);
            p=p->lchild;
        }
        else{
            Pop(&s,&p);
            printf("%d ",p->data);
            p=p->rchild;
        }
    }
    printf("\n");
    
}
void subOrderByStack(BiTree T){
    SqStack s;
    InitStack(&s);
    BiTree p=T;
    BiTree r=NULL;//记录最近访问
    while (p||!StackEmpty(s))
    {
        if(p){
            Push(&s,p);
            p=p->lchild;
        }
        else{
            GetTop(s,&p);
            if(p->rchild&&p->rchild!=r){
                p=p->rchild;
            }
            else{
                Pop(&s,&p);
                printf("%d ",p->data);
                r=p;
                p=NULL;//关键
            }
        }
    }
    printf("\n");
}


/**
 * @msg: 层次遍历（队列）
 * @param {BiTree} T
 * @return {*}
 */
void levelOrder(BiTree T){
    SqQueue Q;
    InitQueue(&Q);
    BiTNode *p;
    EnQueue(&Q,T);
    while(!IsEmpty(Q)){
        DeQueue(&Q,&p);
        printf("%d ",p->data);
        if(p->lchild!=NULL){
            EnQueue(&Q,p->lchild);
        }
        if(p->rchild){
            EnQueue(&Q,p->rchild);
        }
    }
}

//   1 
//  / 
// 2   3
int height,width;
//T为二叉树的根节点,a是数组的起始地址,i,j是当前节点在数组中的位置
//如果节点有孩子,其孩子的j坐标为 j±(height-i+1)/2
void fillArray(BiTree T,int *a,int i, int j)
{
    int ti,tj;
    if(T) //如果该位置有节点
    {
        *(a+(i*width)+j) = T->data; //向数组该点填入字符
        if(T->lchild) //有左右孩子给对应的连接线,左右孩子的值在下一层递归赋
        {
            //将该点与其左孩子之间的连线全部填上'/'
            for(ti=i+1,tj=j-1;tj>j-(height-i+1)/2;tj--)
            {
                *(a+((ti)*width)+tj) = -1;
                ti++;
            }
        }
        if(T->rchild)
        {
            for(ti=i+1,tj=j+1;tj<j+(height-i+1)/2;tj++)
            {
                *(a+((ti)*width)+tj) = -2;
                ti++;
            }
        }
        //经过循环,ti恰好指到其孩子所在的层
        fillArray(T->lchild, a, ti, j-(height-i+1)/2);
        fillArray(T->rchild, a, ti, j+(height-i+1)/2);
    }
}

void printBiTree(BiTree T)
{
    int i,j;
    int n = maxHeight(T); //计算出深度n
    //在计算机中数据以二进制形式存储,所以一个数据左移1位就相当于乘以2的1次方
    width = (2<<n)-3;  // 2^(n+1)-3
    height = (2<<(n-1))-1; // 2^n-1
    int *a = (int *)malloc(sizeof(int) * (width*height)); // 申请空间
 
    // 空间初始化为0
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            *(a+(i*width)+j) = 0;
        }
    }
 
    //调用之前定义好的函数,填充打印数组
    fillArray(T, a, 0, (width-1)/2);
 
    //根据打印数组的内容来实现打印
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            if(*(a+(i*width)+j) == -1)
            {
                printf("/");
            }else if(*(a+(i*width)+j) == -2)
            {
                printf("\\");
            }else if(*(a+(i*width)+j) == 0)
            {
                printf(" ");
            }else
            {
                printf("%d", *(a+(i*width)+j));
            }
        }
        printf("\n");
    }
    free(a);
}