/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> res;
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        set<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            s.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (s.find(nums2[i]) != s.end()) result.insert(nums2[i]);
        }
        for (set<int>::iterator it = result.begin(); it != result.end(); ++it) {
            res.push_back(*it);
        }
        return res;
    }
};
// @lc code=end

