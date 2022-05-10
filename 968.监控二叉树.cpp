/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int res;
    int traversal(TreeNode * cur) {
        if (!cur) return 2; // 空节点，该节点有覆盖
        int left = traversal(cur->left); //左
        int right = traversal(cur->right); //右
        if (left == 2 && right == 2) return 0; // 左右节点都有覆盖
        else if (left == 0 || right == 0) { //左或右节点无覆盖
            res++;
            return 1; 
        }
        else return 2; //else if (left == 1 || right == 1)
    }
    int minCameraCover(TreeNode* root) {
        if (traversal(root) == 0) res++; // root 无覆盖
        return res;
    }
};
// @lc code=end

