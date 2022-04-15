/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (char c : s) {
            if (!res.empty() && res.back() == c) {
                res.erase(res.size() - 1, 1);
                continue;
            }
            res += c;
        }
        return res;
    }
};

/*
超时
class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> s1;
        while (1) {
            int initSize = s.size();
            for (int i = 0; i < initSize; i++) {
                s1.push(s[i]);
            }
            s.clear(); 
            while (!s1.empty()) {
                if (!s.empty() && s[0] == s1.top()) {
                    s1.pop();
                    s.erase(0, 1);
                }
                if (!s1.empty()) {
                    s.insert(s.begin(), s1.top());
                    s1.pop();
                }    
            }    
            if (s.size() == initSize) break;
        } 
        return s;
    }
};
*/
// @lc code=end

