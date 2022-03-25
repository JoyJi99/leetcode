/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        long mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (mid * mid > x) right = mid - 1;
            else if (mid * mid < x) left = mid + 1;
            else return mid;
        }
        if (mid * mid < x && (mid + 1) * (mid + 1) > x) return mid; 
        else return mid - 1; 
    }
};
// @lc code=end

