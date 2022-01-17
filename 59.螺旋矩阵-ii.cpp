/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int flag = 1;//上横
        int row = 0;
        int col = 0;
        int len = n - 1;
        int num = 1;
        while(flag <= (n / 2) * 4){
            if(flag % 4 == 1){//上横
                for(int i = col; i < col + len; i++){
                    res[row][i] = num;
                    num++;
                }
                col = col + len;
            }
            if(flag % 4 == 2){//右竖
                for(int i = row; i < row + len; i++){
                    res[i][col] = num;
                    num++;
                }
                row = row + len;
            }
            if(flag % 4 == 3){//下横
                for(int i = col; i > col - len; i--){
                    res[row][i] = num;
                    num++;
                }
                col = col - len;
            }
            if(flag % 4 == 0){//左竖
                for(int i = row; i > row - len; i--){
                    res[i][col] = num;
                    num++;
                }
                row = row - len + 1;
                col++;
                len -= 2;
            }           
            flag++;
        }
        if(n % 2 != 0) res[n/2][n/2] = n*n;//奇数  
        return res;
    }
};
// @lc code=end

