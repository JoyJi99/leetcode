/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> s;
        bool flag = false;
        while(!s.empty() || root){
            while(root){
                s.push(root);
                root = root->left;
            }
            if(flag) return s.top();
            root = s.top();
            s.pop();
            if(p == root){
                flag = true;
            }
            root = root->right;
        }
        return NULL;
    }
};
