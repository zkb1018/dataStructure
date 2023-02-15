/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-01-18 14:51:39
 * @LastEditors: KB
 * @LastEditTime: 2023-01-18 15:01:11
 */
/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//递归实现
struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    struct ListNode *last=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return last;
}
// @lc code=end

