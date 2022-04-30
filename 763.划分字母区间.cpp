/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        int hash[27] = {0}; // i为字符，hash[i]为字符出现的最后位置
        for (int i = 0; i < s.size(); i++) { // 统计每一个字符最后出现的位置
            hash[s[i] - 'a'] = i; //不断更新
        }
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, hash[s[i] - 'a']); // 找到字符出现的最远边界 
            if (right == i) {
                res.push_back(i - left + 1);
                left = i + 1;
            }
        }
        return res; 
    }
};
// @lc code=end

