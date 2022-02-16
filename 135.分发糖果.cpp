/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> counts(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {//从左到右，保证右比左大
            if (ratings[i - 1] < ratings[i]) counts[i] = counts[i-1] + 1;
        }
        for (int i = ratings.size() - 2; i >= 0; i--) { //从右到左，保证左比右大     
            if (ratings[i] > ratings[i + 1]) {
                counts[i] = max(counts[i+1] + 1, counts[i]);
            }
        }
        return accumulate(counts.begin(), counts.end(), 0);
    }
};
// @lc code=end

