/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
/*
hs哈希表维护的是s字符串中滑动窗口中各个字符出现多少次，ht哈希表维护的是t字符串各个字符出现多少次。
如果hs哈希表中包含ht哈希表中的所有字符，并且对应的个数都不小于ht哈希表中各个字符的个数，
那么说明当前的窗口是可行的，可行中的长度最短的滑动窗口就是答案
*/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht; //2个map
        for (auto c : t) ht[c]++; //t字母对应次数 
        string res;
        for (int i = 0, j = 0, cnt = 0; i < s.size(); i++) {
            hs[s[i]]++; //s字母对应次数 
            if (hs[s[i]] <= ht[s[i]]) cnt++;//cnt计数长度
            while (j < s.size() && hs[s[j]] > ht[s[j]]) hs[s[j++]]--;//j是left
            if (cnt == t.size() && (res == "" || i - j + 1 < res.size()))
                res = s.substr(j, i - j + 1);
        }
        return res;
    }
};
/*
cnt: 先找到了一个大的合法区间，然后不断去向左缩小或者向右扩展这个合法区间，
寻找最小临界值，cnt的值只会被更新一次，满足条件后，再也不会变了
*/
// @lc code=end

