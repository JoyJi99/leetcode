/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp);
        int lo = intervals[0][0];
        int hi = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= hi) {
                hi = max(intervals[i][1], hi);
            }
            else {
                res.push_back(vector<int>{lo, hi});
                lo = intervals[i][0];
                hi = intervals[i][1];
            }
        }
        res.push_back(vector<int>{lo, hi});
        return res;
    }
};
// @lc code=end

