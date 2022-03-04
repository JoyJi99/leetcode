/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        ListNode * fast = head;
        ListNode * slow = head;
        stack<ListNode *> s;
        while(fast && fast->next) {
            s.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) slow = slow->next; //双数
        while (slow) {
                if((s.top())->val == slow->val) {
                    slow = slow->next;
                    s.pop();
                }
                else return false;
        }
        return true; 
    }
};
// @lc code=end

