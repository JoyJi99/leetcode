/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedarrayToBST(vector<int>& nums, int lo, int hi){
        if(lo > hi) return NULL;
        int ind = (hi + lo)/2; 
        TreeNode* root = new TreeNode(nums[ind]);
        root->left = sortedarrayToBST(nums, lo, ind-1);
        root->right = sortedarrayToBST(nums, ind+1, hi);
        return root;
    } 

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedarrayToBST(nums, 0, nums.size()-1);
    }
};
// @lc code=end

