/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        stack<ListNode *> s;
        ListNode * cur = head;
        while(cur) {
            s.push(cur);
            cur = cur->next;
        }
        cur = head;
        while(s.top() != cur) {
            ListNode * nex = cur->next;
            ListNode * last = s.top();
            s.pop();
            cur->next = last;
            cur = nex; 
            if(last != nex) {
                last->next = nex;
            } 
            else break;
        }
        cur->next = nullptr;
    }
};
// @lc code=end

