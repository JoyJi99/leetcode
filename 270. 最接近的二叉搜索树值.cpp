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
    int closestValue(TreeNode* root, double target) {
        int val, closest = root->val;
        while (root) {
            val = root->val;
            closest = abs(val - target) < abs(closest - target) ? val : closest;
            root =  target < root->val ? root->left : root->right;
        }
        return closest;
    }
};

/*
    void inorder(TreeNode* root, priority_queue<pair<double,int> >& pq, double target) {
        if(!root) return;
        inorder(root->left, pq, target);
        pq.push(pair<double,int> (-abs(root->val - target), root->val));
        inorder(root->right, pq, target);
    }
    
    int closestValue(TreeNode* root, double target) {
        priority_queue<pair<double,int> > pq;
        inorder(root, pq, target);
        return pq.top().second;
    }
*/
