/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int res = 0;
        sort(points.begin(), points.end(), cmp);
        long left = LONG_MIN;
        long right = LONG_MAX;
        for (int i = 0; i < points.size(); i++) {
            if (points[i][1] < right) right = points[i][1];
            if (points[i][0] > left || right < points[i][0]) {
                res++;
                left = points[i][1];
                right = points[i][1];
            }
        }
        return res;
    }
};
// @lc code=end

