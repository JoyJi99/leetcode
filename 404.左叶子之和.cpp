/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int temp = 0;
        if (root->left && !root->left->left && !root->left->right) temp = root->left->val;
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + temp;
    }
};

/*
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        //迭代法 —— 前中后序都可，这里用前序
        int res = 0;
        if (!root) return 0;
        stack<TreeNode*> s;
        while (!s.empty() || root) {
            while (root) {
                if (root->left && !root->left->left && !root->left->right) res += root->left->val;
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            root = root->right;
        }
        return res; 
    }
};
*/
// @lc code=end

