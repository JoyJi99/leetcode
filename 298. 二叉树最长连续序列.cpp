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
    int res = 0;
    void longestConsecutive(TreeNode* root, TreeNode* pre, int temp){
        if(!root) return;
        if(pre && root->val == pre->val+1) temp++; //同时解决一般情况和根节点
        else temp = 1;
        res = max(res, temp);       
        longestConsecutive(root->left, root, temp); //temp当全局变量会出错
        longestConsecutive(root->right, root, temp);
    }
    int longestConsecutive(TreeNode* root) {
        longestConsecutive(root, NULL, 0);
        return res;
    }
};
