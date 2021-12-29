/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
#include <algorithm>
using namespace std;
class Solution {
private:
    int maxRes = INT_MIN;//定义全局变量
    //拿到一边包括root的最大sum
    int preorder(TreeNode* root){
        if(!root) return 0;
        int left = max(preorder(root->left),0);//与0比较，避免负数情况
        int right = max(preorder(root->right),0);
        maxRes = max(maxRes, root->val + left + right);
        return root->val + max(left,right);  
    } 
public:
    int maxPathSum(TreeNode* root) { 
        preorder(root);
        return maxRes;
    }
};
// @lc code=end

