/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    void backtracking(vector<int>& nums, vector<int>& used){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true) continue;
            temp.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            temp.pop_back();
            used[i] = false;
        }
    }      
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};
// @lc code=end

