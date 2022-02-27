/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n]; // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
        memset(dp, 0, sizeof(dp));//初始化
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        string ans = "";
        ans += s[0];//length为1的情况
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i == 1 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        if (ans.size() < j - i + 1) ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

