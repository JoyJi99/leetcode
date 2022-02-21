/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * before = dummy;
        ListNode * after = head;
        ListNode * cursor = nullptr;
        while (true) {
            cursor = after;
            for (int i = 0; i < k; i++) {
                if (cursor == nullptr) return dummy->next;
                cursor = cursor->next;
            }
            ListNode * cur = after;
            ListNode * pre = nullptr;
            for (int i = 0; i < k; i++) {
                ListNode * next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            after->next = cur;
            before->next = pre;
            before = after;
            after = cursor;
        }
    }
};
// @lc code=end

