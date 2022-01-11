/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    int sum = 0;
    void backtracking(int k, int n, int start){
        if(sum > n) return;//剪枝
        if(temp.size() == k && sum == n){
            res.push_back(temp);
            return;
        }
        for(int i = start; i <= 9; i++){
            temp.push_back(i);
            sum += i;
            backtracking(k, n, i+1);
            temp.pop_back();
            sum -= i;
        }
    }    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return res;
    }
};
// @lc code=end

