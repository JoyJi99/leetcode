/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    void pathSum(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int>& temp){
        if(!root) return;
        targetSum -= root->val;
        temp.push_back(root->val);
        if(targetSum == 0 && !root->left && !root->right) {
            res.push_back(temp);
        }
        pathSum(root->left, targetSum, res, temp);
        pathSum(root->right, targetSum, res, temp);
        temp.pop_back();//回溯 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        pathSum(root, targetSum, res, temp);
        return res; 
    }
};
// @lc code=end

