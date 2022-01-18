/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {    
public:
    bool isMatch(string s, string p) {
        int lens = s.length();
        int lenp = p.length();
        if(lenp == 0) return lens == 0;//p中无可继续匹配的元素
        bool firstMatch = lens > 0 && (s[0] == p[0] || p[0] == '.');
        if(lenp > 1 && p[1] == '*'){
            return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));//匹配0个 ｜｜ 匹配n个
        }
        else{
            return firstMatch && isMatch(s.substr(1), p.substr(1));//s的长度需要大于等于1，但先运行firstMatch
        }
    }
};
// @lc code=end

