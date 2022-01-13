/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true) continue;       
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;    
            temp.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            used[i] = false;
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return res;
    }
};
// @lc code=end

