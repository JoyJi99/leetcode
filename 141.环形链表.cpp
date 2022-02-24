/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode * reverseList(ListNode * head) {
        ListNode * cur = head;
        ListNode * pre = nullptr;
        while(cur) {
            ListNode * next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next; 
        }
        return pre;
    }

    bool hasCycle(ListNode *head) {
        ListNode * newHead = reverseList(head);
        if (head && head->next && newHead == head) return true;
        return false;
    }
};

/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode *> s;
        ListNode * temp = head;
        while (temp) {
            if(s.find(temp) == s.end()){
                s.insert(temp);
            }
            else return true;
            temp = temp->next; 
        }
        return false;
    }
};
*/
// @lc code=end

