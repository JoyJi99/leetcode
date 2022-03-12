/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key != root->val) {
            if (key < root->val) root->left = deleteNode(root->left, key);
            else root->right = deleteNode(root->right, key);
        }
        else {
            if (!root->left) root = root->right;
            else if (!root->right) root = root->left;
            else {
                TreeNode * right = root->right;
                root = root->left;
                TreeNode * cur = root;
                while (cur->right) {
                    cur = cur->right;
                }
                cur->right = right; 
            }
        }
        return root;
    }
};
// @lc code=end

