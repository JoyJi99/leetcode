/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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

/*
//中序遍历iterate方法 left,root,right
while(!myStack.empty() || root != nullptr){
    while(root != nullptr){
        myStack.push(root);
        root = root->left;
    }
    root = myStack.top();
    myStack.pop();
    res.push_back(root->val);
    root = root->right;
}
return res;
*/
#include <iostream>
#include <stack>
using namespace std;
class BSTIterator {
public:
    stack<TreeNode*> myStack;
    BSTIterator(TreeNode* root){
        pushToLeft(root);   
    }
    
    int next() {
        if(myStack.empty()){
            return -1;
        }
        TreeNode* curNode = myStack.top();
        myStack.pop();
        int val = curNode->val;
        curNode = curNode->right;
        pushToLeft(curNode);
        return val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
private:    
    void pushToLeft(TreeNode* root){
        while(root != NULL){
            myStack.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

