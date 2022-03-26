/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] == nums[slow]) {
                continue;
            }
            else {
                nums[++slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};
// @lc code=end

