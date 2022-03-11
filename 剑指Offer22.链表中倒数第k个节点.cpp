/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution { //快慢指针
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head) return NULL;
        ListNode * former = head;
        ListNode * latter = head;
        for(int i = 1; i <= k; i++) {
            former = former->next;
        }
        while (former) {
            former = former->next;
            latter = latter->next;
        }
        return latter;
    }
};
/* 
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head) return NULL;
        ListNode * cur = head;
        stack<ListNode*> s;
        while (cur) {
            s.push(cur);
            cur = cur->next;
        }
        for(int i = 1; i < k; i++) {
            s.pop();
        }
        return s.top();
    }
};
*/
