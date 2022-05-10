/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int res = 0;
        int minPrice = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice) minPrice = prices[i]; // 情况二：相当于买入
            if (prices[i] >= minPrice && prices[i] <= minPrice + fee) { //情况三：保持原有状态（因为此时买则不便宜，卖则亏本）
                continue;
            }
            // 计算利润，可能有多次计算利润，最后一次计算利润才是真正意义的卖出
            if (prices[i] > minPrice + fee) {
                res += prices[i] - minPrice - fee;
                minPrice = prices[i] - fee; // 情况一，这一步很关键
            }
        } 
        return res;
    }
};
// @lc code=end

