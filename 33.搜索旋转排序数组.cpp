/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) return mid;
            if (nums[lo] <= nums[mid]) {//左边有序
                if (target >= nums[lo] && target < nums[mid]) hi = mid - 1;
                else lo = mid + 1; 
            }
            else { //右边有序 nums[lo] > nums[mid]
                if (target > nums[mid] && target <= nums[hi]) lo = mid + 1;
                else hi = mid - 1;
            }
        } 
        return -1;
    }
};
// @lc code=end

