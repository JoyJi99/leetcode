/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sBackNum = 0;
        int tBackNum = 0;
        int i = s.size() - 1;
        int j = t.size() - 1;
        while (1) {
            while (i >= 0) { //从后向前消除s的退格，遇到不需退的break
                if (s[i] == '#') sBackNum++;
                else {
                    if (sBackNum == 0) break;
                    else sBackNum--;
                }
                i--;
            }
            while (j >= 0) { //t同理
                if (t[j] == '#') tBackNum++;
                else {
                    if (tBackNum == 0) break;
                    else tBackNum--;
                }
                j--; 
            }
            //比较i，j现在指向的位置
            if (i == -1 && j == -1) return true; 
            if (i == -1 || j == -1) return false;
            if (s[i] != t[j]) return false;
            i--;
            j--;
        }
         
    }
};
// @lc code=end

