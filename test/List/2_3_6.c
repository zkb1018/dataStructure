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
int ListInsert_L(LinkList *L, int i, ElemType e)
{
    Link h, s;
    if (!LocatePos(*L, i - 1, &h))
        return 0;
    if (!MakeNode(&s, e))
        return 0;
    InsFirst(h, s);
    L->length++;
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
void DeleteByValue(LinkList *L, ElemType x)
{
    Link q = L->head;
    while (q->next)
    {
        if (q->next->data == x)
        {
            Link p = q->next;
            q->next = q->next->next;
            L->length--;
            // free(p);
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

/**
 * @msg: 删除L中最小值的结点
 * @param {LinkList} L
 * @return {*}
 */
void DelMinNode(LinkList *L)
{
    Link q = L->head;
    Link min = L->head->next;
    Link pre = L->head;
    while (q->next)
    {
        if (min->data > q->next->data)
        {
            min = q->next;
            pre = q;
        }
        q = q->next;
    }
    L->length--;
    pre->next = min->next;
    // free(min);
}

/**
 * @msg: 就地逆置 空间复杂度O(1)
 * @param {LinkList} L
 * @return {*}
 */
void ReverseList(LinkList *L)
{
    Link p, q;
    p = L->head->next;
    L->head->next = NULL;
    while (p)
    {
        q = p;
        p = p->next;
        q->next = L->head->next;
        L->head->next = q;
    }
}

/**
 * @msg: 插入排序从小到大
 * @param {LinkList} *L
 * @return {*}
 */
void SortList(LinkList *L)
{
    Link p, q;
    p = L->head->next;
    L->head->next = NULL;
    while (p)
    {
        q = p;
        p = p->next;
        Link t = L->head;
        while (t->next && q->data >= t->next->data)
        {
            t = t->next;
        }
        q->next = t->next;
        t->next = q;
    }
}
int main()
{
    LinkList L;
    InitLinkList(&L);
    addTestData(&L);
    toString(L);
    ListInsert_L(&L, 2, 5);
    ListInsert_L(&L, 3, 4);
    toString(L);
    DeleteByValue(&L, 4);
    toString(L);
    ReverseToString(L);
    DelMinNode(&L);
    toString(L);
    // ReverseList(&L);
    SortList(&L);
    toString(L);
    return 0;
}
