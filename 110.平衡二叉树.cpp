/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        //3种情况：左右子树不平衡，左子树不平衡，右子树不平衡
        //先自己，后左右
        int l = depth(root->left);
        int r = depth(root->right);       
        if(abs(l-r) > 1) return false;
        if(!isBalanced(root->left)) return false;
        if(!isBalanced(root->right)) return false;        
        return true;
    }

    int depth(TreeNode* root){
        if(!root) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        return max(l,r) + 1;
    }
};
// @lc code=end

