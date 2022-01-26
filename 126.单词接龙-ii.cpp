/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution {
private:
    void findChildren(string word, unordered_set<string>& next, unordered_set<string>& dict, unordered_map<string, vector<string>>& children) {
        string parent = word;
        for (int i = 0; i < word.size(); i++) {
            char t = word[i];
            for (int j = 0; j < 26; j++) {
                word[i] = 'a' + j;
                if (dict.find(word) != dict.end()) {
                    next.insert(word);
                    children[parent].push_back(word);
                }
            }
            word[i] = t;
        }
    }
    //回溯
    void genLadders(string beginWord, string endWord, unordered_map<string, vector<string>>& children, vector<string>& ladder, vector<vector<string>>& ladders) {
        if (beginWord == endWord) {
            ladders.push_back(ladder);
        } else {
            for (string child : children[beginWord]) {
                ladder.push_back(child);
                genLadders(child, endWord, children, ladder, ladders);
                ladder.pop_back();
            }
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), current, next;//把所有word装入set
        if (dict.find(endWord) == dict.end()) {
            return {};
        }
        unordered_map<string, vector<string>> children;
        vector<vector<string>> ladders;
        vector<string> ladder;
        current.insert(beginWord);
        ladder.push_back(beginWord);
        while (true) {
            for (string word : current) {//一层一层构造图，不回头
                dict.erase(word);
            }
            for (string word : current) {//构造与word只差一个字母的set
                findChildren(word, next, dict, children);
            }
            if (next.empty()) {//已构造完整个图
                break;
            }
            if (next.find(endWord) != next.end()) {//已到达想要的层，退出
                genLadders(beginWord, endWord, children, ladder, ladders);
                break;
            }
            current.clear();
            swap(current, next);//进入到下一层构造
        }
        return ladders;
    }
};
/*
 超时
class Solution {
private:
    vector<vector<string>> res;
    vector<string> temp;
    int tempSize;

    bool isValid(string word1, string word2){
        if(word1[0] == '*' || word2[0] == '*') return false;
        int count = 0;
        for(int i = 0; i < word1.size(); i++){
           if(word1[i] != word2[i]) count++;
           if(count > 1) return false; 
        }
        return true;
    }

    void backtracking(string beginWord, string endWord, vector<string>& wordList){
        if(!res.empty() && tempSize > res[0].size()) return;//剪枝
        if(isValid(beginWord, endWord)){
            temp.push_back(endWord);
            if(res.empty() || res[0].size() == tempSize + 1) res.push_back(temp);
            else if(res[0].size() > tempSize + 1){
                res.clear();
                res.push_back(temp);
            }
            temp.pop_back();
            return; 
        }
        for(int i = 0; i < wordList.size(); i++){
            if(!isValid(beginWord, wordList[i])) continue;
            temp.push_back(wordList[i]);
            tempSize++;
            string s = wordList[i];
            wordList[i] = "*";
            backtracking(s, endWord, wordList);
            temp.pop_back();
            wordList[i] = s;
            tempSize--;
        }
    }    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        bool findEnd = false;
        for(int i = 0; i < wordList.size(); i++){
            if(endWord == wordList[i]){
                findEnd = true;
                break;
            }
        }
        if(!findEnd) return res;
        temp.push_back(beginWord);
        tempSize++; 
        backtracking(beginWord, endWord, wordList);
        return res;
    }
};  
 */
// @lc code=end

