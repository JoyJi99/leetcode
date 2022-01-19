/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
private:
    int res;
    bool isValid(vector<vector<int>>& vec, int n, int row, int col){
        for(int i = 0; i < row; i++){
            if(vec[i][col] == 1) return false;
        }
        int j = col;
        for(int i = row-1; i >= 0; i--){          
            j++;
            if(j < n && vec[i][j] == 1) return false;
        }
        int m = col;
        for(int i = row-1; i >= 0; i--){
            m--;
            if(m >= 0 && vec[i][m] == 1) return false;
        }
        return true;
    }   
    void backtracking(vector<vector<int>>& vec, int n, int row){
        if(row == n){
            res += 1;
            return;
        }
        for(int i = 0; i < n; i++){
            if(!isValid(vec, n, row, i)) continue;
            vec[row][i] = 1;
            backtracking(vec, n, row+1);
            vec[row][i] = 0;
        }
    } 
public:
    int totalNQueens(int n) {
        vector<vector<int>> vec(n, vector<int>(n, 0));
        backtracking(vec, n, 0);
        return res;
    }
};
// @lc code=end

