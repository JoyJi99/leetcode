/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int hei = matrix.size() - 1;
        int wid = matrix[0].size() - 1;
        int col = 0;
        int row = 0;
        while(col <= wid && row <= hei){
            for(int i = col; i <= wid; i++){
                res.push_back(matrix[row][i]);
            }
            row++; 
            for(int i = row; i <= hei; i++){
                res.push_back(matrix[i][wid]);
            }
            wid--;
            for(int i = wid; i >= col && row <= hei; i--){
                res.push_back(matrix[hei][i]);
            }
            hei--;
            for(int i = hei; i >= row && col <= wid; i--){
                res.push_back(matrix[i][col]);
            }
            col++; 
        }       
        return res;
    }
};
// @lc code=end

