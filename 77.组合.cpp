/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp; 
    void backtracking(int n, int k, int start){
        if(temp.size() == k){
            res.push_back(temp);
            return;
        }
        for(int i = start; i <= n - (k - temp.size()) + 1; i++){//剪枝优化
            temp.push_back(i);
            backtracking(n, k, i+1);
            temp.pop_back();
        }
    }    
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }
};
// @lc code=end

