/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
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
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        Node* n1 = root;
        while (!q.empty()) {
            n1 = q.front();
            q.pop();
            if(!q.empty()) {
                Node* n2 = q.front();
                if(n1 && n2) n1->next = n2;         
            }
            if(n1){
                if(n1->left) q.push(n1->left);
                if(n1->right) q.push(n1->right);
            }
            else{
                if(q.size()>0) q.push(NULL);
            }   
        }
        return root;        
    }
};
// @lc code=end

