/*
 *  static link list
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 3
typedef int ElemType;
typedef struct
{
	ElemType data;
	int cur;
} component, SLinkList[MAXSIZE];
component dataHead;		// 记录数据表头结点
static int tmpHead = 0; // 记录备用表头结点
void toString(SLinkList S)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		printf("pos%d:|%5d|%5d|\n", i, S[i].data, S[i].cur);
	}
}
int LocateElem_SL(SLinkList S, ElemType e)
{
	int i = S[0].cur;
	while (i && S[i].data != e)
	{
		i = S[i].cur;
	}
	return i;
}

void InitSpace_SL(SLinkList space)
{
	dataHead.cur = -1;
	for (int i = 0; i < MAXSIZE - 1; ++i)
	{
		space[i].data = 0;
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
}

int Malloc_SL(SLinkList space)
{
	int i = space[0].cur;
	if (space[0].cur)
		space[0].cur = space[i].cur;
	return i;
}

void Free_SL(SLinkList space, int k)
{
	space[k].cur = space[0].cur;
	space[k].data = 0;
	space[0].cur = k;
}

int GetElem(SLinkList S, int i)
{
	int p = dataHead.cur;
	int j = 1;
	if (i == 0)
		return 0;
	while (p != -1 && j < i)
	{
		p = S[p].cur;
		j++;
	}
	if (j != i)
	{ // 位置超过长度
		return -1;
	}
	return p;
}

void SLinkListInsert(SLinkList S, int i, ElemType e)
{

	if (i > MAXSIZE || i <= 0)
	{
		printf("未找到该位置！\n");
		return;
	}
	int pre = GetElem(S, i - 1);
	if (pre == -1)
	{
		printf("该位置不存在\n");
		return;
	}
	int tmp = Malloc_SL(S);
	if (tmp == 0)
	{
		printf("空间不足\n");
		return;
	}
	if (pre == 0)
	{
		S[tmp].cur = dataHead.cur;
		S[tmp].data = e;
		dataHead.cur = tmp;
	}
	else
	{
		S[tmp].cur = S[pre].cur;
		S[tmp].data = e;
		S[pre].cur = tmp;
	}
}

void SLinkListDelete(SLinkList S, int i, ElemType *e)
{
	if (i > MAXSIZE || i <= 0)
		return;
	int index = GetElem(S, i);
	int preIndex = GetElem(S, i - 1);
	if (index != -1)
	{
		*e = S[index].data;
		S[preIndex].cur = S[index].cur;
		Free_SL(S, index);
	}
}
int main()
{
	SLinkList S;
	InitSpace_SL(S);
	SLinkListInsert(S, 1, 3);
	SLinkListInsert(S, 1, 33);
	SLinkListInsert(S, 1, 31);
	SLinkListInsert(S, 2, 2);
	SLinkListInsert(S, 6, 31);
	toString(S);
	printf("\n*******************\n");
	int del;
	SLinkListDelete(S, 4, &del);
	toString(S);
	return 0;
}