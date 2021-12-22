/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
#include <stack>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void construct_paths(TreeNode* root, string path, vector<string>& paths){
        if(!root) return;
        path += to_string(root->val);
        if(!root->left && !root->right){
            paths.push_back(path);
        }
        else{
            path += "->";
            construct_paths(root->left, path, paths);
            construct_paths(root->right, path, paths);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
       vector<string> paths;
       construct_paths(root, "", paths);
       return paths;    
    }
};
// @lc code=end

