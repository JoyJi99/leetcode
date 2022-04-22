/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val) return root;
        if (val < root->val) return searchBST(root->left, val);
        if (val > root->val) return searchBST(root->right, val);
        return nullptr;
    }
};

/*
class Solution { //iteration
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root) {
            if (val < root->val) root = root->left;
            else if (val > root->val) root = root->right;
            else return root;
        }
        return NULL;
    }
};
*/

/*
class Solution { //非二叉搜索树
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val == val) return root;
        TreeNode * left = searchBST(root->left, val);
        TreeNode * right = searchBST(root->right, val);
        if (!right) return left;
        else return right;
    }
};
*/
// @lc code=end

