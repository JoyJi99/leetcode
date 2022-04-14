class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int u = 0;
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while (u <= d && l <= r) {
            for (int i = l; i <= r; i++) {
                res.push_back(matrix[u][i]);
            }
            u++;
            for (int i = u; i <= d; i++) {
                res.push_back(matrix[i][r]);
            }
            r--;
            for (int i = r; i >= l && u <= d; i--) {
                res.push_back(matrix[d][i]);
            }
            d--;
            for (int i = d; i >= u && l <= r; i--) {
                res.push_back(matrix[i][l]);
            }
            l++;
        }
        return res;
    }
};
