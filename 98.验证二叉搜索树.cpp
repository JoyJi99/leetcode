/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        long long val = (long long)INT_MIN - 1;
        while (!s.empty() || root) {
            while(root) {
               s.push(root);
               root = root->left;
            }
            root = s.top();
            s.pop();
            if(root->val <= val) return false;
            val = root->val;
            root = root->right; 
        }
        return true;
    }    
};
// @lc code=end
/*
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
            return false;
        }
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
*/

