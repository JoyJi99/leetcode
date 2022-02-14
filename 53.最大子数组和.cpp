/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;//result可能是负数
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
           count += nums[i];
           if (count > result) result = count; // 取区间累计的最大值（相当于不断确定最大子序终止位置）
           if (count < 0) { // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和 count <= 0也可
               count = 0;
           } 
        }
        return result;
    }
};
// @lc code=end

