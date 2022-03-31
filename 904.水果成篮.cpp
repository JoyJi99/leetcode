/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) { //求含有2个元素的最长连续子序列
        set<int> s;
        int left = 0;
        int res = 0;
        for(int r = 0; r < fruits.size(); r++) {
            if (s.size() < 2 && s.find(fruits[r]) == s.end()) {
                s.insert(fruits[r]);
            }
            if (s.find(fruits[r]) == s.end()) {
                s.clear();
                s.insert(fruits[r]);
                s.insert(fruits[r - 1]); 
                left = r - 1;
                for (int i = r - 2; i >= 0; i--) {
                    if (fruits[i] != fruits[left]) break;
                    else left = i;
                }
            }   
            res = (r - left + 1 > res) ? r - left + 1 : res; 
        }
        return res;
    }
};
/*
class Solution { //滑动窗口另一种写法，表达相同意思，空间复杂度会更好
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0,right = 0,ans = 0;
        int ln = fruits[left],rn = fruits[right];
        while(right < fruits.size()){
            if(fruits[right] == rn || fruits[right] == ln){
                ans = max(ans,right + 1 - left);
                right++;
            }else{
                left = right - 1;
                ln = fruits[left];
                while(left >= 1 && fruits[left - 1] == ln) left--;
                rn = fruits[right];
                ans = max(ans,right + 1 - left);
            }
        }
        return ans;
    }
};
*/
// @lc code=end

