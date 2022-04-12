/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            //swap的第一种实现形式
            char temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            /* swap的第二种实现形式——位运算
            s[i] ^= s[j];
            s[j] ^= s[i];
            s[i] ^= s[j];
            */
            right--;
            left++; 
        }        
    }
};
// @lc code=end

