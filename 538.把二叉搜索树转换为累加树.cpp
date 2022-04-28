/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
public:
    int count = 0;
    TreeNode* convertBST(TreeNode* root) { //右根左
        if (!root) return nullptr;
        convertBST(root->right);
        root->val += count;
        count = root->val;
        convertBST(root->left);
        return root;
    }
};

/*
class Solution {
private:
    int pre; // 记录前一个节点的数值
    void traversal(TreeNode* cur) { // 右中左遍历
        if (cur == NULL) return;
        traversal(cur->right);
        cur->val += pre;
        pre = cur->val;
        traversal(cur->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        pre = 0;
        traversal(root);
        return root;
    }
};
*/
// @lc code=end

