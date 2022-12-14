/*
 *  static link list
 */

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
typedef int ElemType;
typedef struct{
	ElemType data;
	int cur;
}component,SLinkList[MAXSIZE];

int LocateElem_SL(SLinkList S,ElemType e){
	int i=S[0].cur;
	while(i&&s[i].data!=e){
		i=s[i].cur;
	}
	return i;
}

void InitSpace_SL(SLinkList space){
	for(int i=0;i<MAXSIZE-1;++i) space[i].cur=i+1;
	space[MAXSIZE-1].cur=0;
}

int Malloc_SL(SLinkList space){
	int i=space[0].cur;
	if(space[0].cur) space[0].cur=space[i].cur;
	return i;
}

void Free_SL(SLinkList space,int k){
	space[k].cur=space[0].cur;
	space[0].cur=k;
}

