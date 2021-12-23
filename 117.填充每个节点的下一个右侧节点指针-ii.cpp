/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#include <iostream>
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node * cur = root;
        Node head(INT_MIN);
        Node * headCur = &head;
        while (true){
            while(cur){
                if(cur->left){
                    headCur->next = cur->left;
                    headCur = headCur->next;
                }
                if(cur->right){
                    headCur->next = cur->right;
                    headCur = headCur->next;
                } 
                cur = cur->next;   
            }
            cur = head.next;
            head.next = NULL;
            headCur = &head;
            if(!cur) break;
        }    
        return root;
    }
};
// @lc code=end

