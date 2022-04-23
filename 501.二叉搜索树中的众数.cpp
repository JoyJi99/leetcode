/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> res;
    TreeNode * pre;
    int count = 1;
    int temp = 1;
    void traversal(TreeNode* root) {
        if (!root) return;
        traversal(root->left);
        if (pre) {
            if (pre->val == root->val) temp++;              
            else temp = 1;
        }
        if (count <= temp) {
            if (temp > count) {
                res.clear();
                count = temp;
            } 
            res.push_back(root->val); 
        }    
        pre = root;
        traversal(root->right);
    }    
public:
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return res;
    }
};
// @lc code=end

