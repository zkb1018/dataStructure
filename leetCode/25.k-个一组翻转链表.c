/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-01-18 15:20:50
 * @LastEditors: KB
 * @LastEditTime: 2023-01-18 15:44:34
 */
/*
 * @lc app=leetcode.cn id=25 lang=c
 *
 * [25] K 个一组翻转链表
 *
 * 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* a,struct ListNode* b){
    struct ListNode* pre,*cur,*nxt;
    pre=NULL,cur=a,nxt=a;
    while(cur!=b){
        nxt=nxt->next;
        cur->next=pre;
        pre=cur;
        cur=nxt;
    }
    return pre;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if(head==NULL) return NULL;
    struct ListNode *a,*b;
    a=b=head;
    for(int i=0;i<k;i++){
        if(b==NULL) return head;
        b=b->next;
    }
    struct ListNode* newHead=reverse(a,b);
    a->next=reverseKGroup(b,k);
    return newHead;

}
// @lc code=end

