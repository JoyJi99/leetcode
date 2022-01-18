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
    ListNode* plusOne(ListNode* head) {
        ListNode * sentinel = new ListNode(0, head);
        ListNode * notNine = sentinel;
        notNine->next = head;
        while(head){ //找到最右端的非9
            if(head->val != 9) notNine = head;
            head = head->next; //head遍历整个list
        }
        notNine->val++;
        notNine = notNine->next;
        while(notNine){
            notNine->val = 0;
            notNine = notNine->next;
        }
        return sentinel->val != 0 ? sentinel : sentinel->next;
    }
};
