/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    //map映射  C++中，全局变量只能声明、初始化，而不能赋值
    map<char, string> m = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} 
    };

    vector<string> res;
    string temp;
    void backtracking(string digits, int ind){
        if(temp.size() == digits.size()){
            res.push_back(temp);
            return;
        }
        string s = m[digits[ind]];
        for(int i = 0; i < s.length(); ++i){
            temp.push_back(s[i]);
            backtracking(digits, ind+1);
            temp.pop_back();
        }
    }    
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return res; //return []和return [""]有区别
        backtracking(digits, 0);
        return res;
    }
};
// @lc code=end

