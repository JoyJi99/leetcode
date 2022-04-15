/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
public:
    void removeExtraSpaces(string & s) {
        int slow = 0;
        int fast = 0;
        while (fast < s.size() && s[fast] == ' ') { //移除前面的空格
            fast++;
        }
        for (; fast < s.size(); fast++) { //移除中间的空格
            if (s[fast] == ' ' && fast >= 1  && s[fast - 1] == s[fast]) continue;
            s[slow++] = s[fast]; 
        }
        if (s[slow - 1] == ' ') s.resize(slow - 1); //移除末尾空格
        else s.resize(slow);//重置字符串大小
    }
    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s.begin(), s.end());
        int fast = 0, slow = 0;
        //reverse(s.begin(), s.begin() + 4);
        for (; fast <= s.size(); fast++) {
            if (s[fast] != ' ') continue;
            else {
                reverse(s.begin() + slow, s.begin() + fast);
                slow = fast + 1;
            }
        } 
        reverse(s.begin() + slow, s.end());
        return s;
    }
};
// @lc code=end

