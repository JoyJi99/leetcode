/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) { //初始版本
        int lo = 0;
        int hi = nums.size() - 1;
        int mid;
        while (lo <= hi) {
            mid = (hi + lo) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] > nums[lo]) { //左边有序
                if (nums[mid] > target && target >= nums[lo]) hi = mid - 1;
                else lo = mid + 1;
            }
            else if (nums[mid] < nums[lo]) { //右边有序 
                if (nums[mid] < target && nums[hi] >= target) lo = mid + 1;
                else hi = mid - 1;
            } 
            else { // mid和lo相等, 整个遍历 
                for (int i = lo; i <= hi; i++) {
                    if (nums[i] == target) return true;
                }
                break; 
            }       
        }
        return false;
    }
};
/*
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid;
        while (lo <= hi) {
            mid = (hi + lo) / 2;
            if (nums[mid] == target) return true;
            if (nums[lo] == nums[mid] && nums[mid] == nums[hi]) { //重复情况
                lo++;
                hi--;
            }
            else if (nums[mid] >= nums[lo]) { //左边有序
                if (nums[mid] > target && target >= nums[lo]) hi = mid - 1;
                else lo = mid + 1;
            }
            else { //右边有序 nums[mid] < nums[lo] 
                if (nums[mid] < target && nums[hi] >= target) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return false;
    }
};
*/
// @lc code=end

