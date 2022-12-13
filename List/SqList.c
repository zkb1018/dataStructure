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

void GetElem(SqList L,int i,ElemType *e){
	if(i<1||i>L.length+1) return;
	*e=L.elem[i-1];
}

int LocateElem(SqList L,ElemType e){
	for(int i=0;i<L.length;i++){
		if(L.elem[i]==e)
			return i;
	}
	return -1;
}

void PriorElem(SqList L,ElemType cur_e,ElemType *pre_e){
	int index=LocateElem(L,cur_e);
	if(index==-1||index==0) return;
	else{
		*pre_e=L.elem[index-1];
	}
}

void NextElem(SqList L,ElemType cur_e,ElemType *next_e){
	int index=LocateElem(L,cur_e);
	if(index==-1||index==L.length-1) return;
	else *next_e=L.elem[index+1];
}
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

void ListDelete(SqList *L,int i,ElemType *e){
	if(i<1||i>L->length+1) return;
	*e=L->elem[i-1];
	for(int j=i-1;j<L->length;j++){
		L->elem[j]=L->elem[j+1];
	}
	//free(&L->elem[L->length-1]);
	L->length--;
	if(L->listSize>LIST_INIT_SIZE){
		L->listSize-=LISTINCREMENT;
	}
	
	
} 
int main(){
	SqList L;
	int tmp=InitList(&L);
	ListInsert(&L,1,5);
	ListInsert(&L,1,4);
	ListInsert(&L,1,6);
	ListInsert(&L,1,4);
	ListInsert(&L,1,11);
	int delKey;
	//ListDelete(&L,3,&delKey);
	GetElem(L,1,&delKey);
	printf("initList:%d\n",tmp);
	printf("is empty list:%d\n",ListEmpty(L));
	printf("list:");
	toString(L);
	printf("*********************\n");
	ListLength(L);
	printf("*********************\n");
	printf("get located:%d\n",LocateElem(L,21));
	printf("%d\n",delKey);
	printf("*********************\n");
	int pre;
	PriorElem(L,11,&pre);
	printf("priorElem:%d\n",pre);
	printf("*********************\n");
	int next;
	NextElem(L,11,&next);
	printf("nextelem:%d\n",next);
	return 1;

}

