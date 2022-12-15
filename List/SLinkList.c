/*
 *  static link list
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
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
	space[0].cur = k;
}
int InitSLinkList(SLinkList S)
{
	int tempBody = 0, body = 0;
	int i = 0;
	InitSpace_SL(S);
	body = Malloc_SL(S);
	// 建立首元结点
	S[body].data = 1;
	S[body].cur = 0;
	// 声明一个变量，把它当指针使，指向链表的最后的一个结点，当前和首元结点重合
	tempBody = body;
	for (i = 2; i < 4; i++)
	{
		int j = Malloc_SL(S); // 从备用链表中拿出空闲的分量
		S[j].data = i;		  // 初始化新得到的空间结点
		S[tempBody].cur = j;  // 将新得到的结点链接到数据链表的尾部
		tempBody = j;		  // 将指向链表最后一个结点的指针后移
	}
	S[tempBody].cur = 0; // 新的链表最后一个结点的指针设置为0
	return body;
}

void SLinkListInsert(SLinkList S, int i, ElemType e)
{

	if (i > MAXSIZE)
	{
		printf("未找到该位置！\n");
		return;
	}

	if (dataHead.cur == -1)
	{
		int tmp = Malloc_SL(S);
		dataHead.cur = tmp;
		S[tmp].data = e;
		S[tmp].cur = -1;
	}
	else
	{
		int k = 0;
		int j = dataHead.cur;
		while (j != -1)
		{
			k++;
			j = S[j].cur;
		}
		if (k < i - 1)
		{
			printf("未找到该位置！\n");
			return;
		}
		int tmp = Malloc_SL(S);
		S[tmp].cur = S[k].cur;
		S[tmp].data = e;
		S[k].cur = tmp;
	}
}
int main()
{
	SLinkList S;
	dataHead.cur = -1;
	InitSpace_SL(S);
	SLinkListInsert(S, 1, 3);
	SLinkListInsert(S, 1, 33);
	SLinkListInsert(S, 1, 31);

	toString(S);
	return 0;
}