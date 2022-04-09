/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m; //key = a + b; value = 次数
        for (int a : nums1) {
            for (int b : nums2) {
                m[a + b]++;
            }
        }
        int count = 0;
        for (int c : nums3) {
            for (int d : nums4) {
                if (m.find(-(c + d)) != m.end()) count += m[-(c + d)];
            }
        }
        return count;
    }
};
// @lc code=end

