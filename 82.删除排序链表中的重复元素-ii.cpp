/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode * dummy = new ListNode();
        dummy->next = head;
        ListNode * cur = head;
        ListNode * pre = dummy;
        ListNode * nxt = cur;
        while(cur) {
            if (nxt->next && nxt->next->val == cur->val) {
                nxt = nxt->next;
            }
            else {
                if(cur == nxt){
                    pre = cur;
                    cur = cur->next;                   
                } 
                else {
                    pre->next = nxt->next;
                    cur = pre->next;
                }
                nxt = cur;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

