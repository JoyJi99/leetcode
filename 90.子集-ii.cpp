/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;   
    void backtracking(int start, vector<int>& nums, vector<bool>& used){
        res.push_back(temp);
        for(int i = start; i < nums.size(); i++){
            // used[i - 1] == true，说明同一树支candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 而我们要对同一树层使用过的元素进行跳过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            temp.push_back(nums[i]);
            used[i] = true;
            backtracking(i+1, nums, used);
            //回溯
            temp.pop_back();
            used[i] = false;
        }
    } 
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<bool> used(nums.size(), false);
       sort(nums.begin(), nums.end());//去重需要排序 
       backtracking(0, nums, used); 
       return res;
    }
};
// @lc code=end

