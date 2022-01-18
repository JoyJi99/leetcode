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
        int hei = matrix.size() - 1;//down
        int wid = matrix[0].size() - 1;//right
        int col = 0;//left
        int row = 0;//up
        while(col <= wid && row <= hei){
            for(int i = col; i <= wid; i++){//up
                res.push_back(matrix[row][i]);
            }
            row++; 
            for(int i = row; i <= hei; i++){//right
                res.push_back(matrix[i][wid]);
            }
            wid--;
            for(int i = wid; i >= col && row <= hei; i--){//down
                res.push_back(matrix[hei][i]);
            }
            hei--;
            for(int i = hei; i >= row && col <= wid; i--){//left
                res.push_back(matrix[i][col]);
            }
            col++; 
        }       
        return res;
    }
};
// @lc code=end

