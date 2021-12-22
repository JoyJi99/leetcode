// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem99.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <stack>
using namespace std;
class Solution {
public:
    void recoverTree(TreeNode* root) {
        bool tag = true; 
        TreeNode* oldRoot = root;
        while(tag){
            root = oldRoot; 
            tag = false; 
            stack<TreeNode*> s;
            long long val = (long long)INT_MIN - 1;
            TreeNode* t;
            while (!s.empty() || root){
                while(root){
                    s.push(root);
                    root = root->left;
                }
                root = s.top();
                s.pop(); 
                if(root->val <= val){
                    int temp = root->val;
                    root->val = val;
                    t->val = temp;
                    tag = true; 
                }
                val = root->val;
                t = root;
                root = root->right;
            }
        }     
    } 
};
// @lc code=end

/*
void recoverTree(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* x = nullptr;        
    TreeNode* y = nullptr;
    TreeNode* pred = nullptr;
    while (!s.empty() || root != nullptr) {
        while (root != nullptr) {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        if (pred != nullptr && root->val < pred->val) {
            y = root;
            if (x == nullptr) {
                x = pred;
            }
            else break;
        }
        pred = root;
        root = root->right;
    }
    swap(x->val, y->val);
}
*/
