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
    bool isSame(TreeNode* root, int& res){
        bool status = true;
        if(root->left) {
            status = isSame(root->left, res) && root->val == root->left->val && status;
        }
        if(root->right) {
            status = isSame(root->right, res) && root->val == root->right->val && status;
        }
        if(status) ++res;
        return status;
    }

    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        if(!root) return 0;
        isSame(root, res);
        return res;
    }
};
