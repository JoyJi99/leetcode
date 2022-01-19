/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
private:
    vector<string> res;
    string s; 
    void backtracking(int n, int left, int right, bool left_paren){
        if(left == 0 && right == 0){
            res.push_back(s);
            return;
        }
        if(left == 0 && left_paren == true) return; 
        if(right == 0) return;
        if(left_paren){
            for(int i = 1; i <= left; i++){
                for(int j = 0; j < i; j++) s += "(";
                backtracking(n, left-i, right, false);
                for(int j = 0; j < i; j++) s.pop_back(); 
            }
        }
        else{
            for(int i = 1; i <= right; i++){
                if(right-left < i) continue;//")"的数量  大于  已用的“（” - 已用的“）”
                for(int j = 0; j < i; j++) s += ")";
                backtracking(n, left, right-i, true);
                for(int j = 0; j < i; j++) s.pop_back(); 
            }
        }       
    }    
public:
    vector<string> generateParenthesis(int n) {
        backtracking(n, n, n, true);
        return res; 
    }
};
// @lc code=end

 