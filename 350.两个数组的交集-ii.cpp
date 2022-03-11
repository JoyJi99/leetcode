/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            if (m.find(nums1[i]) == m.end()) m.insert(pair<int, int>(nums1[i], 1));
            else m[nums1[i]] += 1;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (m.find(nums2[i]) != m.end()) {
                if (m[nums2[i]] > 0) {
                    m[nums2[i]] -= 1;
                    res.push_back(nums2[i]);
                }
            }
        }
        return res;
    }
};
// @lc code=end

