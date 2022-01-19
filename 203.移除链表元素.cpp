/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        ListNode* sentinel = new ListNode(-1, head);
        ListNode* prev = sentinel;
        while(true){
            if(head->val != val){
                prev = head;
                head = head->next; 
            } 
            else{
                ListNode * temp = head; 
                prev->next = head->next;
                head = head->next;
                delete temp;
            }             
            if(head == nullptr) break;
        }
        head = sentinel->next;
        delete sentinel;
        return head; 
    }
};
// @lc code=end

