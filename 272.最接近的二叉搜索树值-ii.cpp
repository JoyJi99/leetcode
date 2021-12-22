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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<pair<double, int> > pq;
        vector<int> res;
        stack<TreeNode*> s;
        while(!s.empty() || root){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            pair<double, int> pr(-abs(root->val - target), root->val);
            pq.push(pr);
            root = root->right;
        }
        for(int i = 0; i<k; i++){
            int ans = pq.top().second;
            res.push_back(ans);
            pq.pop();
        }
        return res;
    }
};
