/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int res;
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int j = 0;
        for(int i = 0; i < g.size();){
            if(j >= s.size()) break;
            if(g[i] <= s[j]){
                res++;
                j++;
                i++;
            } 
            else j++; 
        }
        return res; 
    }
};
// @lc code=end

