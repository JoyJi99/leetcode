/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
private:
    vector<string> res;
    bool isValid(string word1, string word2, int start){
        if(word1.substr(start).size() < word2.size()) return false;
        for(int i = 0; i < word2.size(); i++){
            if(word2[i] != word1[start + i]) return false;
        }
        return true;
    }
    void backtracking(string& s, vector<string>& wordDict, int start){
        if(s.size() == start){
            s.pop_back();
            res.push_back(s);
            s += ' ';
            return;
        }
        for(int i = 0; i < wordDict.size(); i++){
            if(!isValid(s, wordDict[i], start)) continue;
            s.insert(start + wordDict[i].size(), " ");
            start += wordDict[i].size() + 1;
            backtracking(s, wordDict, start);
            s.erase(start - 1, 1);
            start -= wordDict[i].size() + 1;             
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        backtracking(s, wordDict, 0);
        return res;
    }
};
// @lc code=end

