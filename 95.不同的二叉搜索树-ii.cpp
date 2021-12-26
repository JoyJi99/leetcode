/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
using namespace std;
class Solution {
private:
    vector<TreeNode*> generateTrees(int start, int end){
        vector<TreeNode*> res;
        if(start > end){
            res.push_back(NULL);//NULL和空不同，空则不进入下方循环，res为空
            return res;
        } 
        for(int i = start; i < end+1; i++){          
            vector<TreeNode*> left = generateTrees(start, i-1);
            vector<TreeNode*> right = generateTrees(i+1, end);
            for(int j = 0; j < left.size(); j++){              
               for(int m = 0; m < right.size(); m++){
                   TreeNode* root = new TreeNode(i);//放外面前面push的树会被后面的覆盖，产生相同解 
                   root->left = left[j];
                   root->right = right[m];    
                   res.push_back(root);              
               }             
            }
        }       
        return res;
    }    
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1,n);
    }
};
// @lc code=end

