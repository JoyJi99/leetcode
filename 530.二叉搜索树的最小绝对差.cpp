/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
class Solution {
private:
    int res = INT_MAX;
    TreeNode* pre;
    void traversal(TreeNode* cur) { //中序, 递归中记录前一个指针
        if (cur == NULL) return;
        traversal(cur->left);   // 左
        if (pre != NULL){       // 中
            res = min(res, cur->val - pre->val);
        }
        pre = cur; // 记录前一个
        traversal(cur->right);  // 右
    }    
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return res;
    }
};
/*
class Solution {
private:
    vector<int> vec;
    TreeNode* pre;
    void traversal(TreeNode* root) { //中序
        if (root == NULL) return;
        traversal(root->left);
        vec.push_back(root->val); // 将二叉搜索树转换为有序数组
        traversal(root->right);
    }    
public:
    int getMinimumDifference(TreeNode* root) {
        vec.clear();
        traversal(root);
        int res = INT_MAX;
        for (int i = 1; i < vec.size(); i++) {
            res = min(res, vec[i] - vec[i - 1]);
        }
        return res;
    }
};
*/
// @lc code=end

