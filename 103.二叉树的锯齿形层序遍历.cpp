/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        deque<TreeNode*> q;
        vector<int> cur_vec;
        int order = 1;//right order
        if(!root) return res; 
        q.push_back(NULL);
        q.push_back(root);
        while(!q.empty()) {
            TreeNode* t;
            if(order == -1){
                t = q.front();
                q.pop_front();
            }
            else if (order == 1){
                t = q.back();
                q.pop_back();
            }
            if(t != NULL){
                cur_vec.push_back(t->val);
                if(order == -1){
                    if(t->right) q.push_back(t->right);
                    if(t->left) q.push_back(t->left);
                }
                else if(order == 1){
                    if(t->left) q.push_front(t->left);
                    if(t->right) q.push_front(t->right);
                }   
            }
            else{
                res.push_back(cur_vec);
                cur_vec.resize(0);
                order *= -1;//change order
                if(q.size()>0){
                    if(order == 1) q.push_front(NULL);
                    if(order == -1) q.push_back(NULL);
                }
            }
        }
        return res;
    
    }
};
// @lc code=end

/*
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    if (root == NULL) {
        return vector<vector<int> > ();
    }
    vector<vector<int> > result;

    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while ( !nodesQueue.empty()) {
        int size = nodesQueue.size(); //用size截断，不用加null
        vector<int> row(size); 
        for (int i = 0; i < size; i++) {
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            // find position to fill node's value
            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node->val;
            if (node->left) {
                nodesQueue.push(node->left);
            }
            if (node->right) {
                nodesQueue.push(node->right);
            }
        }
        // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}
*/

