/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len  = prices.size();
        vector<vector<int> > dp(len, vector<int>(2));
        dp[0][0] = -prices[0]; //持有
        dp[0][1] = 0; //不持有
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(prices[i] + dp[i - 1][0], dp[i - 1][1]);
        }
        return dp[len - 1][1];
    }
};
/*
版本二：
从递推公式可以看出，dp[i]只是依赖于dp[i - 1]的状态，
因此只需记录当前天的dp状态和前一天的dp状态，可以使用滚动数组来节省空间
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(2, vector<int>(2)); //这里只开辟了一个2 * 2大小的二维数组
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], prices[i] + dp[(i - 1) % 2][0]);
        }
        return dp[(len - 1) % 2][1];
    }
};
*/
/*
贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            low = min(low, prices[i]); //找到左边最小值
            res = max(res, prices[i] - low); // 直接取最大区间利润
        }
        return res;
    }
};
*/
// @lc code=end

