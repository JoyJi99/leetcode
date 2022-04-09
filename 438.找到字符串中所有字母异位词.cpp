/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> goal(26), temp(26), res;
        for (char c : p) {
            goal[c - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            temp[s[i] - 'a']++;
            if (i >= p.size()) temp[s[i - p.size()] - 'a']--;
            if (goal == temp) res.push_back(i - p.size() + 1);
        }
        return res;
    }
};
/*
超时
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        sort(p.begin(), p.end());
        int l = p.size();
        int end = s.size() - l;
        for (int i = 0; i <= end; i++) {
            string temp = s.substr(i, l);
            sort(temp.begin(), temp.end());
            if (p.compare(temp) == 0) res.push_back(i);
        }
        return res;
    }
};
*/
// @lc code=end

