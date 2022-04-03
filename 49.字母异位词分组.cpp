/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string> > m;
        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i]; 
            sort(key.begin(), key.end());
            m[key].push_back(strs[i]);
        }
        for (unordered_map<string, vector<string>>::iterator it = m.begin(); it != m.end(); ++it) {
            res.push_back(it->second);
        }
        return res; 
    }
};
// @lc code=end

