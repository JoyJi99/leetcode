/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        ListNode * dummy  = new ListNode();
        dummy->next = head;
        ListNode * p1 = dummy;
        ListNode * p2 = dummy->next;
        while (p1->next && p2->next) {
            p1->next = p2->next;
            p1 = p1->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p1->next;
            p2 = p1->next;
        }
        return dummy->next;
    }
};
// @lc code=end

