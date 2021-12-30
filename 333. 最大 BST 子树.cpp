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
    bool isBST(TreeNode* root){
        return isBST(root, INT_MIN, INT_MAX);
    }
    bool isBST(TreeNode* root, int min, int max){
        if(!root) return true;
        return root->val > min && root->val < max && isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
    }

    int count(TreeNode* root){
        if(!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }

    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        if(isBST(root)) return count(root);
        int left = largestBSTSubtree(root->left);
        int right = largestBSTSubtree(root->right);
        return max(left, right);
    }
};
