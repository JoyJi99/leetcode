/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if (nums[j] + nums[i] > target - nums[left] - nums[right]) { //nums[j] + nums[left] + nums[right] > target - nums[i] int会溢出
                        right--;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                    else if (nums[j] + nums[i] < target - nums[left] - nums[right]) {
                        left++;
                        while (left < right && nums[left] == nums[left - 1]) left++; 
                    } 
                    else {
                        res.push_back(vector<int>{nums[i],nums[j], nums[left], nums[right]});
                        while (left < right && nums[right - 1] == nums[right]) right--;
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        right--;
                        left++; 
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

