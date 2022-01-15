/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
private:
    int helper(int lo, int hi, vector<int>& nums, int target){
        if(lo > hi) return -1;
        int ind = (lo + hi)/2;
        if(nums[ind] == target) return ind;
        else if(nums[ind] > target) return helper(lo, ind-1, nums, target);
        else return helper(ind+1, hi, nums, target);
    }    
public:
    int search(vector<int>& nums, int target) {
        return helper(0, nums.size()-1, nums, target);
    }
};
// @lc code=end

