/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& used, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0' || used[i][j] == 1) {
            return;
        }
        used[i][j] = 1; //记录是'1'的点放入used，'0'不放
        dfs(grid, used, i + 1, j);
        dfs(grid, used, i - 1, j);
        dfs(grid, used, i, j - 1);
        dfs(grid, used, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int col = grid[0].size();
        int row = grid.size();
        int res = 0;
        vector<vector<int>> used(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (used[i][j] != 1) {
                    if (grid[i][j] == '0') continue;
                    dfs(grid, used, i, j); //一个岛
                    res++; 
                }
            }
        } 
        return res;
    }
};
// @lc code=end

