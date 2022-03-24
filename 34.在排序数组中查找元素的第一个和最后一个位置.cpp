/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int resL = lowerBound(nums, target);
        int resR = lowerBound(nums, target + 1) - 1;
        if (resL < nums.size() && nums[resL] == target) {
            return {resL, resR};
        }
        else return {-1, -1};
    }
    int lowerBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return left;
    }
};
/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid; 
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else break;
        }
        if (left > right) return vector<int>{-1, -1};
        int resR = mid;
        int resL = mid;
        for (int i = mid + 1; i <= right; i++) {
            if (nums[i] == target) resR = i;
            if (nums[i] != target) break;
        } 
        for (int i = mid - 1; i >= left; i--) {
            if (nums[i] == target) resL = i;
            if (nums[i] != target) break; 
        }
        return vector<int>{resL, resR};
    }
};
*/
// @lc code=end

