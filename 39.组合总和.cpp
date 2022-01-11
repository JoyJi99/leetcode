/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    int sum = 0;
    void backtracking(vector<int>& candidates, int target, int start){
        if(sum > target) return;
        if(sum == target){
            res.push_back(temp);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, i);
            temp.pop_back();
            sum -= candidates[i];
        }
    } 
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);
        return res;
    }
};
// @lc code=end

