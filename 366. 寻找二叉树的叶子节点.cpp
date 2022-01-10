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
    vector<vector<int>> res;
    void helper(TreeNode* root, TreeNode* pre, vector<int>& vec){
        if(!root) return;
        if(!root->left && !root->right) {
            vec.push_back(root->val);
            if(pre){
                if(pre->left){
                    if(pre->left == root) pre->left = NULL;
                }
                if(pre->right){
                    if(pre->right == root) pre->right = NULL;
                }
            } 
        }
        pre = root;
        helper(root->left, pre, vec);
        helper(root->right, pre, vec);
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        TreeNode* pre = new TreeNode(0, root, NULL);
        while(pre->left){
            vector<int> vec;
            helper(root, pre, vec);
            res.push_back(vec);
        }
        return res;
    }
};
