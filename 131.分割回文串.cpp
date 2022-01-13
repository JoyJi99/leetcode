/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
private:
    vector<vector<string>> res;
    vector<string> temp;
    bool isPalin(int start, int end, string str){//双指针
        for(int i = start, j = end; i < j; i++, j--){
            if(str[i] != str[j]) return false;
        }
        return true;
    }
    void backtracking(string s, int start){       
        if(start >= s.size()){//切割完成
            res.push_back(temp);
            return;
        }
        for(int i = start; i < s.size(); i++){//[start, i]是要截取的子串
            string str = s.substr(start, i - start + 1);
            if(isPalin(0, str.length()-1, str)) temp.push_back(str);
            else continue;
            backtracking(s, i+1);
            temp.pop_back();
        }
    }      
public:
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
};
// @lc code=end

