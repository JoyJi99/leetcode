/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;
        long mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (mid * mid < num) left = mid + 1;
            else if (mid * mid > num) right = mid - 1;
            else return true;
        }
        return false;
    }
};
// @lc code=end

