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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root) return root;
        TreeNode* head = root->left;
        TreeNode* right = root->right;
        TreeNode* newHead;
        TreeNode* newRight;
        TreeNode* orig = root;
        while(head){
            newHead = head->left;
            newRight = head->right;
            head->left = right;
            head->right = root;
            if(root == orig){
                root->right = NULL;
                root->left = NULL;
            }          
            root = head;
            head = newHead;
            right = newRight;
        }
        return root;
    }
};
