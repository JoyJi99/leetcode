/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> money = {{5,0}, {10,0}, {20,0}};
        for (int i = 0; i < bills.size(); i++) {
           if (bills[i] == 5) {
               money[5] += 1;
           }
           else if (bills[i] == 10) {
               if (money[5] != 0) {
                   money[10] += 1;
                   money[5] -= 1;
               }
               else return false;
           }
           else {
               if (money[5] != 0 && money[10] != 0) {
                   money[20] += 1;
                   money[10] -= 1;
                   money[5] -= 1; 
               }
               else if (money[10] == 0 && money[5] >= 3) {
                   money[20] += 1;
                   money[5] -= 3;
               }
               else return false;
           } 
        }
        return true;
    }
};
// @lc code=end

