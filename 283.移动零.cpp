/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {// move all the nonzero elements advance
            if (nums[fast] != 0) {
                nums[slow++] = nums[fast];
            }
        }
        for (; slow < nums.size(); slow++) {
            nums[slow] = 0;
        }
    }
};
/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        //slow找是0的，fast找不是0的
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[slow] != 0) {
                slow++;
                continue;
            }
            if (nums[slow] == 0) {
                if (nums[fast] == 0) continue;
                else {
                    nums[slow++] = nums[fast];
                    nums[fast] = 0;
                }
            } 
        }
    }
};
*/
// @lc code=end

