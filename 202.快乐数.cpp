/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    int getSum(int n) { // 取数值各个位上的单数之和
        int sum = 0;
        while (n) { //直到n为0，即十位为0
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) { 
        unordered_set<int> set;
        while (1) {
            int sum = getSum(n);
            if (sum == 1) {
               return true; 
            }
            if (set.find(sum) != set.end()) { // 如果这个sum曾经出现过，说明已经陷入了无限循环了，立刻return false
                return false;
            }
            else set.insert(sum);
            n = sum;
        }        
    }
};
// @lc code=end

