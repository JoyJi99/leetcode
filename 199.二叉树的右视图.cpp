/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> cur_vec;
        vector<int> res;
        if(!root) return res;
        q.push(root);
        q.push(NULL);
        while (!q.empty()){
            TreeNode * t = q.front();
            q.pop();
            if(t != NULL){
                cur_vec.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            else{
                res.push_back(cur_vec.back());
                cur_vec.resize(0);
                if(q.size()>0) q.push(NULL);
            }
        }
        return res;
    }
};
// @lc code=end

