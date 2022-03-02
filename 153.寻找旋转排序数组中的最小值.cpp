/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = (lo + hi) / 2;
        int res = INT_MAX;
        while(lo <= hi) {
            if (nums[lo] <= nums[mid]) {
                res = min(nums[lo], res);
                lo = mid + 1;
            }
            else {
                hi = mid;
                res = min(nums[mid], res);
            }
            mid = (lo + hi) / 2;
        } 
        return res;
    }
};
// @lc code=end

