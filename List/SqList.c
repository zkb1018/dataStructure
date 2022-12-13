#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100 //初始分配空间
#define LISTINCREMENT 10  //存储空间分配增量
typedef int ElemType;   //数据类型
typedef struct{
	ElemType *elem;
	int length;
	int listSize;
} SqList;

//输出
void toString(SqList L){
	for(int i=0;i<L.length;i++){
		printf("%d ",L.elem[i]);
	}
	printf("\n");
}
//构造一个空的线性表
int InitList(SqList* L){
	L->elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem) return 0;
	L->length=0;
	L->listSize=LIST_INIT_SIZE;
	return 1;
}

//销毁线性表

//置为空表

//是否为空
int ListEmpty(SqList L){
	if(L.length==0)
		return 1;
	else
		return 0;
}

//输出长度
void ListLength(SqList L){
	printf("%d\n",L.length);
}

//插入元素
void ListInsert(SqList *L,int i,ElemType e){
	if(i<1||i>L->length+1) return;
	if(L->listSize>=LIST_INIT_SIZE){
		ElemType* newbase=(ElemType *)realloc(L->elem,(L->listSize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase) return;
		L->elem=newbase;
		L->listSize+=LISTINCREMENT;
	}
	if(L->length==0){
		L->elem[0]=e;
		++L->length;
		return;
	}
	for(int j=L->length-1;j>=i-1;j--){
		L->elem[j+1]=L->elem[j];
	}
	L->elem[i-1]=e;

	++L->length;

}
int main(){
	SqList L;
	int tmp=InitList(&L);
	ListInsert(&L,1,5);
	ListInsert(&L,1,4);
	ListInsert(&L,1,6);
	ListInsert(&L,1,4);
	ListInsert(&L,1,11);
	printf("创建空表：%d\n",tmp);
	printf("是否空表：%d\n",ListEmpty(L));
	toString(L);
	ListLength(L);
	return 1;

}

