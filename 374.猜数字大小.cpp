/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        unsigned long lo = 1;
        unsigned long hi = n;
        unsigned long mid;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (guess(mid) == -1) hi = mid - 1;
            else if (guess(mid) == 1) lo = mid + 1;
            else break;
        }
        return mid;
    }
};
// @lc code=end

