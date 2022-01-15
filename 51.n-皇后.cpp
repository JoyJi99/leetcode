/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
private:
    vector<vector<string>> res;
    vector<string> temp;
    string addQ(int ind){
        string str;
        for(int i = 0; i < n; i++){
            if(i == ind) str += "Q";
            else str += "."; 
        }
        return str;
    } 
    void backtracking(int n, int row){
        if(temp.size() == n){
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i++){
            if(i == 0) temp.push_back(addQ(i));
            row++;
            
            
        }
    }    
public:
    vector<vector<string>> solveNQueens(int n) {
        backtracking(n, 0);
        return res;
    }
};
// @lc code=end

