/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
class Solution { //优化：每次分隔不用定义新的数组，而是通过下标索引直接在原数组上操作
private:
    TreeNode* traversal(vector<int>& nums, int left, int right) {//在左闭右开区间[left, right)，构造二叉树
        if (left >= right) return nullptr;
        int maxValueIndex = left; // 分割点下标
        for (int i = left + 1; i < right; ++i) {
            if (nums[i] > nums[maxValueIndex]) maxValueIndex = i;
        }
        TreeNode* root = new TreeNode(nums[maxValueIndex]);
        root->left = traversal(nums, left, maxValueIndex);
        root->right = traversal(nums, maxValueIndex + 1, right);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};

/*
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int max = INT_MIN;
        int ind = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
                ind = i;
            } 
        }
        TreeNode * root = new TreeNode(max); 
        if (ind > 0) {
            vector<int> numsL(nums.begin(), nums.begin() + ind); //左闭右开
            root->left = constructMaximumBinaryTree(numsL);
        } 
        if (ind < nums.size() - 1) {
            vector<int> numsR(nums.begin() + ind + 1, nums.end());
            root->right = constructMaximumBinaryTree(numsR);
        } 
        return root;
    }
};
*/
// @lc code=end

