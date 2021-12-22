/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        queue<TreeNode*> q;
        vector<int> cur_vec;
        if(!root) return res;
        q.push(root);
        q.push(NULL);//null作为每一层的标记
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(t != NULL) {
                cur_vec.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            else {
                res.push_back(cur_vec);
                cur_vec.resize(0);
                if(q.size()>0) q.push(NULL);//添加每一层标记
            }
        }
        return res;
    }
};
// @lc code=end

