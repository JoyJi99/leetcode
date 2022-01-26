/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
private:
    bool backtracking(int i, int j, vector<vector<char>>& board, string& word){
        if(!word.length()) return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0]) return false;
        string s = word.substr(1);
        char c = board[i][j];
        board[i][j] = '*';
        if(backtracking(i, j-1, board, s) || backtracking(i, j+1, board, s) || backtracking(i-1, j, board, s) || backtracking(i+1, j, board, s)) return true;
        board[i][j] = c;
        return false;
    }    
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){   
               if(backtracking(i, j, board, word)) return true; 
            }
        } 
        return false;
    }
};
// @lc code=end

