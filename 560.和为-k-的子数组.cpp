/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int prefixSum = 0;
        int res = 0;
        m[0] = 1;//nums[-1]为0，次数为1
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            if (m.find(prefixSum - k) != m.end()) {
                res += m[prefixSum - k]; //m[]没有但直接用，会在map里增加一条key无value，map的size增大
            } 
            m[prefixSum]++;
        }
        return res;
    }
};
// @lc code=end

