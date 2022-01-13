/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int> > res;
    vector<int> temp;
    int sum = 0;
    void backtracking(vector<int>& candidates, int target, int start, vector<bool>& used){
        if(sum > target) return;
        if(sum == target){
            res.push_back(temp);
            return;
        }        
        for(int i = start; i < candidates.size(); i++){ 
            if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false) continue; 
            temp.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            backtracking(candidates, target, i+1, used);
            temp.pop_back();
            sum -= candidates[i];
            used[i] = false;
        }
    }    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, used);
        return res;
    }
};
// @lc code=end

