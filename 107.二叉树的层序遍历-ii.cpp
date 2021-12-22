/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) return res;
        //vector<int> cur_vec;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            size_t size = q.size(); //size截断每一层
            vector<int> cur_vec; //每层被更新
            for(size_t i = 0; i < size; i++){
                TreeNode* t = q.front();
                q.pop();
                cur_vec.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            res.insert(res.begin(), cur_vec);
            //cur_vec.resize(0); //时间更短，memory usage更少
        }
        return res;
    }
};
// @lc code=end

/*
int depth(TreeNode *root) {
    if (!root) return 0;
    return max(depth(root->left),depth(root->right))+1;
}

void levelOrder(vector<vector<int>> &ans, TreeNode *node, int level) {
    if (!node) return;
    ans[level].push_back(node->val);
    levelOrder(ans,node->left,level-1);
    levelOrder(ans,node->right,level-1);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    int d = depth(root);
    vector<vector<int>> ans(d,vector<int> {});
    levelOrder(ans,root,d-1);
    return ans;
}
*/

