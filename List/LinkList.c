/*
	with head node
*/
#include<stdio.h>
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;



void toString(LinkList L){
	LNode *p=L->next;
	while(p){		
		printf("->%d",p->data);		
		p=p->next;
	}
}

int ListLength(LinkList L){
	int i=0;
	LNode *p=L->next;
	while(p){
		i++;
		p=p->next; 
	}
	return i; 
}

LNode* InitList(){
	LinkList L=(LinkList)malloc(sizeof(LNode));
	L->data=-1;
	L->next=NULL;
	return L;
}

//get the node's point in position i 
LNode* GetElem(LinkList L,int i){
	int j=1;
	LNode *p=L->next;
	if(i==0) return L;
	if(i<1) return NULL;
	while(p&&j<i){
		p=p->next;
		j++;
	}
	return p;
}
void ListInsert(LinkList L,int i,ElemType e){
//	int j=1;
//	LNode *p=L;
//	while(L->next!=NULL&&j<i){
//		j++;
//		p=p->next;
//	}
//	if(i>j||i<1) return;
	LNode *p=GetElem(L,i-1);
	if(p==NULL) return;
	LNode *newNode=(LinkList)malloc(sizeof(LNode));
	newNode->data=e;
	newNode->next=p->next;
	p->next=newNode; 
}

void ListDelete(LinkList L,int i,ElemType *e){
	LNode *p=GetElem(L,i-1);
	if(p==NULL) return;
	LNode *q=p->next;
	*e=q->data;
	p->next=q->next;
	free(q); 
}

int main(){
	LinkList L=InitList(); 
	ListInsert(L,1,4); 
	ListInsert(L,1,14); 
	ListInsert(L,1,24); 
	ListInsert(L,2,11); 
//	L->data=1;
//	L->next=NULL;
	int length=ListLength(L);
	printf("length:%d\n",length);
	//LNode* n=GetElem(L,6);
 	//printf("\n%d\n",n->data);
	toString(L);
	printf("\n******************\n");
	int del;
	ListDelete(L,2,&del);
	toString(L);
	return 0;
}
