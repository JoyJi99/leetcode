/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
private:
    void sumNumbers(TreeNode* root, int& res, string& temp){
        if(!root) return;
        temp += to_string(root->val);
        if(!root->left && !root->right) res += atoi(temp.c_str());
        sumNumbers(root->left, res, temp);
        sumNumbers(root->right, res, temp);
        temp.pop_back();
    }
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
        string temp;
        sumNumbers(root, res, temp);
        return res;
    }
};
// @lc code=end

