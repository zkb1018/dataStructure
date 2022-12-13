#include<stdio.h>
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

int hasNext(LinkList L){
	if(L->next==NULL)return 0;
	else return 1;
}
void toString(LinkList L){
	LinkList p=L;
	while(p->next!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}
int main(){
	LinkList L;
	L->data=1;
	L->next=NULL;
	toString(L);
	return 0;
}
