/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-01-18 13:48:39
 * @LastEditors: KB
 * @LastEditTime: 2023-01-18 14:18:59
 */
/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int add=0;
    struct ListNode *head=NULL,*tail=NULL;

    while (l1!=NULL||l2!=NULL)
    {
        int n1=l1?l1->val:0;
        int n2=l2?l2->val:0;
        int result=n1+n2+add;
        if(!head){
            head=tail=malloc(sizeof(struct ListNode));
            tail->val=result%10;
            tail->next=NULL;
        }else{
            tail->next=malloc(sizeof(struct ListNode));
            tail->next->val=result%10;
            tail=tail->next;
            tail->next=NULL;
        }
        add=result/10;
        if(l1){
            l1=l1->next;
        }
        if(l2){
            l2=l2->next;
        }
    }
    if(add>0){//最高位还存在进位
        tail->next=malloc(sizeof(struct ListNode));
        tail=tail->next;
        tail->val=add;
        tail->next=NULL;
    }
    return head;
    
}
// @lc code=end

