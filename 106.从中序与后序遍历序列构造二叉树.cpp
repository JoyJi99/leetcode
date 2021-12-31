/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int il, int ih, int pl, int ph) {
        if(ph < pl) return NULL;
        TreeNode* root = new TreeNode(postorder[ph]);
        int ind;
        for(int i = il; i <= ih; i++){
            if(inorder[i] == root->val) ind = i; 
        }
        root->left = buildTree(inorder, postorder, il, ind-1, pl, ph-ih+ind-1);
        root->right = buildTree(inorder, postorder, ind+1, ih, ph-ih+ind, ph-1);
        return root; 
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};
// @lc code=end

