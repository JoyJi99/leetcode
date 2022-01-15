/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT32_MAX;
        int sum = 0;
        int subLength = 0;
        int i = 0;//滑动窗口起始位置 
        for(int j = 0; j < nums.size(); j++){//滑动窗口结束位置 
            sum += nums[j];           
            while (sum >= target) {
                subLength = j - i + 1;
                res = res > subLength ? subLength : res;
                sum -= nums[i++];//精髓之处，不断变更i（子序列的起始位置）
            } 
        }
        return res == INT32_MAX ? 0 : res; 
    }
};
// @lc code=end

