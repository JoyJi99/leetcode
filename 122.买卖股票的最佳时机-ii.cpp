/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int res = 0; 
       int lo = INT_MAX;
       int hi = INT_MIN;
       int count = 0;
       for (int i = 0; i < prices.size(); i++) {
           if (prices[i] < hi) {
               lo = hi;
               res += count;
               count = 0;
               hi = INT_MIN;
           }
           if (prices[i] > lo && prices[i] > hi) {
               hi = prices[i];
           }
           if(prices[i] < lo) {
               lo = prices[i];
           } 
           if (hi >= lo) {
               count = hi - lo;
           }
           if (i == prices.size() - 1) res += count; 
       }
       return res; 
    }
};
/*
更简洁写法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            result += max(prices[i] - prices[i - 1], 0);
        }
        return result;
    }
};
*/
// @lc code=end

