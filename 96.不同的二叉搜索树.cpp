/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
private:
    int numTrees(vector<int>& state, int n){
        int res = 0;      
        if(n == 0 || n == 1) return 1;
        else if(state[n] != -1) return state[n];//若state[n]已有，不需再次计算
        for(int i = 1; i <= n; i++){ 
            state[i-1] = numTrees(state, i-1);
            state[n-i] = numTrees(state, n-i);
            res += state[i-1]*state[n-i]; 
        }
        return res;
    }    
public:
    int numTrees(int n) {
        vector<int> state(n+1, -1);//用state记录已计算过的n的答案，减少重复计算
        return numTrees(state, n);
    }
};
/*
cases passed但超时
class Solution {
private:
    int numTrees(int start, int end){
        int res = 0;
        if(start >= end){
            res = 1;
            return res;
        }
        for(int i = start; i <= end; i++){ 
            int left = numTrees(start, i-1);
            int right = numTrees(i+1, end);
            res += left*right; 
        }
        return res;
    }    
public:
    int numTrees(int n) {
        return numTrees(1,n);
    }
};
*/
// @lc code=end

