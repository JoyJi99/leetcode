/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
private:
    bool isValid(vector<vector<char>>& board, int col, int row, int i){

        return true;
    }
    bool backtracking(vector<vector<char>>& board, int col, int row){
        if(row == 9 && col == 9){
            return true;
        }
        for(int i = 0; i < 9; i++){ //遍历行
            //if(isValid(board, col, row, i)) board[row][col] = i;
        }
    }    
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board, 0, 0);
        return board;
    }
};
// @lc code=end

