/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
#include <vector>
using namespace std;
class Solution {
public:
    //用&，不必返回vector<int>，节省memory usage
    void preorderTraversalHelp(TreeNode* root, vector<int>& ans){
        TreeNode * temp = root;
        if (temp != NULL) { //是if不是while
            ans.push_back(temp->val);
            preorderTraversalHelp(temp->left, ans);
            preorderTraversalHelp(temp->right, ans);
        } 
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorderTraversalHelp(root, ans);   
        return ans;
    }
};
// @lc code=end

