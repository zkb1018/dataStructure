/*
 *带头结点链表问题
 */

#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} *Link, *Position;

typedef struct
{
    Link head;
    int length;
} LinkList;

void InitLinkList(LinkList *L)
{
    L = (LinkList *)malloc(sizeof(LinkList));
    Link head = (Link)malloc(sizeof(Link));
    L->length = 0;
    head->next = NULL;
    L->head = head;
}

/**
 * @msg: 将s插入第一个结点前
 * @param {Link} h  链表头节点
 * @param {Link} s  插入结点
 * @return {*}
 */
int InsFirst(Link h, Link s)
{
    s->next = h->next;
    h->next = s;
    return 1;
}
/**
 * @msg:返回p指向L链表中的第i个结点
 * @param {LinkList} L
 * @param {int} i
 * @param {Link} p
 * @return {*}
 */
int LocatePos(LinkList L, int i, Link *p)
{
    if (i < 1 || i > L.length)
        return 0;
    int j = 0;
    Link q = L.head;
    while (q->next && j < i)
    {
        q = q->next;
        j++;
    }
    *p = q;
    return 1;
}
/**
 * @msg:分配p指向值为e的结点
 * @param {Link} p
 * @param {ElemType} e
 * @return {*}
 */
int MakeNode(Link *p, ElemType e)
{
    Link q = (Link)malloc(sizeof(Link));
    if (!q)
        return 0;
    q->data = e;
    *p = q;
}
/**
 * @msg: 在带头节点的单链表L的第i个元素前加入元素e
 * @param {LinkList} *L
 * @param {int} i
 * @param {ElemType} e
 * @return {*}
 */
int ListInsert_L(LinkList L, int i, ElemType e)
{
    Link h, s;
    if (!LocatePos(L, i - 1, &h))
        return 0;
    if (!MakeNode(&s, e))
        return 0;
    InsFirst(h, s);
    return 1;
}
void toString(LinkList L)
{
    Link p = L.head->next;
    while (p)
    {
        printf("->%d", p->data);
        p = p->next;
    }
    printf("\n");
}
void addTestData(LinkList *L)
{
    for (int i = 0; i < 5; i++)
    {
        Link p = (Link)malloc(sizeof(Link));
        p->data = i;
        p->next = L->head->next;
        L->head->next = p;
        L->length++;
    }
}

/**
 * @msg:  删除L中所有值为x的结点 并释放空间
 * @param {LinkList} L
 * @param {ElemType} x
 * @return {*}
 */
void DeleteByValue(LinkList L, ElemType x)
{
    Link q = L.head;
    while (q->next)
    {
        if (q->next->data == x)
        {
            Link p = q->next;
            q->next = q->next->next;
            L.length--;
            // free(q);
            continue;
        }
        q = q->next;
    }
}

/**
 * @msg: 递归反向输出L链表
 * @param {LinkList} L
 * @return {*}
 */
void printNext(Link p)
{
    if (p->next == NULL)
    {
        printf("->%d", p->data);
        return;
    }
    printNext(p->next);
    printf("->%d", p->data);
}
void ReverseToString(LinkList L)
{
    printf("逆序输出：");
    printNext(L.head->next);
    printf("\n");
}

int main()
{
    LinkList L;
    InitLinkList(&L);
    addTestData(&L);
    toString(L);
    ListInsert_L(L, 2, 5);
    ListInsert_L(L, 3, 4);
    toString(L);
    DeleteByValue(L, 4);
    toString(L);
    ReverseToString(L);
    return 0;
}
