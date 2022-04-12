/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public://每隔k个反转k个，末尾不够k个时全部反转
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
                continue;
            }
            // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
            reverse(s.begin() + i, s.begin() + s.size());
        }
        return s;
    }
};
/*
class Solution {
public://每隔k个反转k个，末尾不够k个时全部反转
    string reverseStr(string s, int k) {
        int ind = 2 * k;
        while (1) {
            if (ind > s.size()) {
                if (ind - k <= s.size()) {
                    reverse(s.begin() + ind - 2 * k, s.begin() + ind - k);
                }
                else {
                    reverse(s.begin() + ind - 2 * k, s.end());
                }
                break;
            } 
            else {
                reverse(s.begin() + ind - 2 * k, s.begin() + ind - k);
                ind += 2 * k; 
            } 
        }
        return s;
    }
};
*/
// @lc code=end

