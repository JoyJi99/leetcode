/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
#include <string>
using namespace std;
class Codec {
public:
    void preorder(TreeNode* root, string& str){
        if(!root) {
            str +="#";
            return;
        }
        str += to_string(root->val);
        str += " ";
        preorder(root->left, str);
        str += " ";
        preorder(root->right, str);
    }
    /*
    void add(int toAdd, TreeNode* root){
        TreeNode** cur = &root;
        while(*cur){
            if(toAdd < (*cur)->val) cur = &(*cur)->left;
            else cur = &(*cur)->right;
        }
        *cur = new TreeNode(toAdd);
    }
    */

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        preorder(root, str); 
        return str;       
    }

    TreeNode* mydeserialize(istringstream &ss){
        string tmp;
        ss >> tmp;
        if(tmp == "#"){
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(tmp));
        node->left = mydeserialize(ss);
        node->right = mydeserialize(ss);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       /* 
        TreeNode* root;
        string str;
        for(size_t i = 0; i< data.size(); i++){
            if(data[i] != ',') str += data[i];
            else{
                int toAdd = atoi(str.c_str());
                add(toAdd, root);
                str.clear();
            }   
        }
        return root;
       */
        istringstream ss(data);
        return mydeserialize(ss); 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

