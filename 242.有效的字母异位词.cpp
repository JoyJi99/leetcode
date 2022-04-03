/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) return false;
        }
        return true;    
    }
};
/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hs, ht;
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            hs[s[i]]++;
            ht[t[i]]++;
        }
        for (unordered_map<char,int>::iterator it = hs.begin(); it != hs.end(); ++it) {
            if (ht.find(it->first) == ht.end()) return false;
            if (it->second != ht.find(it->first)->second) return false; 
        }
        return true;    
    }
};
*/
// @lc code=end

