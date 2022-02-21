/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int res = 0;
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(128, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
/*
i不会跳，效率很低
class Solution {
public:
    int res = 0;
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;
        set<char> record;
        int temp = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
               if (record.find(s[j]) == record.end()) {
                   record.insert(s[j]); 
                   temp++;
               }
               else {
                   if (temp > res) res = temp;
                   temp = 0;
                   record.clear();
                   break;
               } 
            }
        }
        return res; 
    }
};
*/
// @lc code=end

