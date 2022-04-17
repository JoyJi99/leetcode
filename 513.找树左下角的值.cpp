/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
class Solution { //最适合层序遍历
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int res;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) { 
                TreeNode * cur = q.front();
                q.pop();
                if (i == 0) res = cur->val; // 记录最后一行第一个元素
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return res;
    }
};

/*
class Solution { //递归
public:
    int maxLen = INT_MIN;
    int maxleftValue;
    void traversal(TreeNode* root, int leftLen) { //前序遍历，保证先左再右
        if (root->left == NULL && root->right == NULL) {  // 中
            if (leftLen > maxLen) {
                maxLen = leftLen;
                maxleftValue = root->val;
            }
            return;
        }
        if (root->left) {  // 左
            leftLen++;
            traversal(root->left, leftLen);
            leftLen--; // 回溯
        }
        if (root->right) {  // 右
            leftLen++;
            traversal(root->right, leftLen);
            leftLen--; // 回溯
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return maxleftValue;
    }
};
*/

/*
代码量少，但时间复杂度太大，每次都在算深度
class Solution {
public:
    int findDepth(TreeNode* root) {
        if (!root) return 0;
        return max(findDepth(root->left), findDepth(root->right)) + 1;
    }
    int findBottomLeftValue(TreeNode* root) {
        if (!root->left && !root->right) return root->val;
        return findDepth(root->left) >= findDepth(root->right) ? findBottomLeftValue(root->left): findBottomLeftValue(root->right);
    }
};
*/
// @lc code=end

