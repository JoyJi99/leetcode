/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        if(root->left != NULL){
            TreeNode* left = root->left;
            root->left = root->right;
            root->right = left;
            TreeNode* t = root;
            while(t->right){
                t = t->right;
            }
            t->right = root->left;
            root->left = NULL;
        }
        flatten(root->right);
    }
};
// @lc code=end

