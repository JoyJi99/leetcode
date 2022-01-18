/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char num){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == num) return false;
        }
        for(int i = 0; i < 9; i++){
            if(board[i][col] == num) return false;
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) { //判断9方格里是否重复
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == num) return false;
            }
        }
        return true;
    }
    bool backtracking(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){ //遍历行
            for(int j = 0; j < 9; j++){//遍历列
                if(board[i][j] != '.') continue;
                for(char num = '1'; num <= '9'; num++){
                    if(isValid(board, i, j, num)){
                        board[i][j] = num;
                        if(backtracking(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;//9个数都试完了，都不行               
            }          
        }
        return true; //遍历完没有返回false，说明找到，因此不需要回溯终止条件
    }    
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};
// @lc code=end

