/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pl, int ph, int il, int ih) {
        if(pl > ph) return NULL;
        TreeNode* root = new TreeNode(preorder[pl]);
        int ind;
        for(int i = il; i <= ih; i++){
            if(inorder[i] == root->val) ind = i;
        } 
        root->left = buildTree(preorder, inorder, pl+1, pl+ind-il, il, ind-1); 
        root->right = buildTree(preorder, inorder, pl+ind-il+1, ph, ind+1, ih); 
        return root;
    } 

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
// @lc code=end

