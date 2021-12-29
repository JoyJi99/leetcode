/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {//注意是BST，左比右小
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val < p->val && root->val < q->val){//第一种情况：p，q均在root的右子树
            return lowestCommonAncestor(root->right, p, q); 
        }
        if(root->val > p->val && root->val > q->val){//第二种情况：p，q均在root的左子树
            return lowestCommonAncestor(root->left, p, q); 
        }
        return root;//第三种情况：p，q分别在一左一右，或p，q其中一个是根节点
    }
};
// @lc code=end

