/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
private:
    vector<vector<string>> res;
    bool isValid(int col, int row, int n, vector<string>& temp){
        //col
        for(int i = 0; i < row; i++){
            if(temp[i][col] == 'Q') return false;
        } 
        //斜线
        for(int i = 0; i < row; i++){
            int j = col + (row - i);
            if(j < n && temp[i][j] == 'Q') return false;          
        }            
        //反斜线
        for(int i = 0; i < row; i++){
            int j = col - (row - i);
            if(j >= 0 && temp[i][j] == 'Q') return false;          
        }   
        return true;
    } 
    void backtracking(int n, int row, vector<string>& temp){
        if(row == n){
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i++){//i为column
            if(isValid(i, row, n, temp)) temp[row][i] = 'Q';
            else continue;
            backtracking(n, row + 1, temp);
            temp[row][i] = '.';           
        }
    }    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n, string(n, '.'));//先都填成.
        backtracking(n, 0, temp);
        return res;
    }
};
// @lc code=end

