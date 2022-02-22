/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {           
            if (nums[i] > 0) return res; // 排序之后如果第一个元素已经大于零，不可能凑成三元组
            //去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            /* 错误去重方法，将会漏掉-1,-1,2 这种情况
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                /* 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }
                else {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    right--;
                    left++;
                }
            }    
        }
        return res;
    }
};
// @lc code=end

