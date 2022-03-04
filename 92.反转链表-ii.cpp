/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode * dummy = new ListNode();
        dummy->next = head;
        ListNode * cur = dummy;
        ListNode * pre = nullptr;
        for (int i = 0; i < left; i++) {
            pre = cur;
            cur = cur->next;
        }
        ListNode * revPre = nullptr;
        for (int i = 0; i < right - left + 1; i++) {
           ListNode * next = cur->next;
           cur->next = revPre;
           revPre = cur;
           cur = next; 
        }
        pre->next->next = cur;
        pre->next = revPre;  
        return dummy->next;
    }
};
/*
class Solution {
public:
    pair<ListNode *, ListNode *> reverseList(ListNode* left, int num) {
        ListNode * cur = left;
        ListNode * pre = nullptr;
        int count = 0;
        while (count < num) {
            ListNode * next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            count++;
        }
        return pair<ListNode *, ListNode *>({pre, cur});
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (right - left == 0) return head; 
        ListNode * cur = head;
        ListNode * pre = nullptr;
        int count = 1; 
        while (count < left) {
            pre = cur;
            cur = cur->next;
            count++;
        }
        pair<ListNode *, ListNode *> res = reverseList(cur, right - left + 1);
        if (left == 1) {
            head = res.first;
        }
        else pre->next = res.first;
        cur->next = res.second;
        return head; 
    }
};
*/
// @lc code=end

