/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int len = s.length(); //加这两行memory usage效率更高
        if (len % 2 != 0) return false;
        stack<int> sta;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') sta.push(')');
            else if (s[i] == '[') sta.push(']');
            else if (s[i] == '{') sta.push('}');
            else if (sta.empty() || s[i] != sta.top()) return false; //必须加sta.empty,否则第一个就是右括号报错
            else sta.pop(); //s[i] == sta.top()
        }
        return sta.empty(); //确定都匹配完了，而不是只有左括号
    }
};
// @lc code=end

