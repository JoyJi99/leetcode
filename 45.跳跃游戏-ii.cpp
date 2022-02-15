/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int cover = 0; // 当前覆盖最远距离下标
        int count = 0; // 记录走的最大步数
        int temp = 0; // 下一步覆盖最远距离下标
        if (nums.size() == 1) return 0;
        for (int i = 0; i < nums.size(); i++) {
            temp = max(i + nums[i], temp);
            if (temp >= nums.size() - 1) {
                    count++;
                    break;
            }
            if (i == cover) {
                count++;
                cover = temp;
            }
        }
        return count;
    }
};
/*
更简便写法
class Solution {
public:
    int jump(vector<int>& nums) {
        int curDistance = 0;    // 当前覆盖的最远距离下标
        int ans = 0;            // 记录走的最大步数
        int nextDistance = 0;   // 下一步覆盖的最远距离下标
        for (int i = 0; i < nums.size() - 1; i++) { // 注意这里是小于nums.size() - 1，这是关键所在
            nextDistance = max(nums[i] + i, nextDistance); // 更新下一步覆盖的最远距离下标
            if (i == curDistance) {                 // 遇到当前覆盖的最远距离下标
                curDistance = nextDistance;         // 更新当前覆盖的最远距离下标
                ans++;
            }
        }
        return ans;
    }
};
当移动下标指向nums.size - 2时：
如果移动下标等于当前覆盖最大距离下标，需要再走一步（即ans++），因为最后一步一定是可以到的终点（题目假设总是可以到达数组的最后一个位置）
如果移动下标不等于当前覆盖最大距离下标，说明当前覆盖最远距离就可以直接达到终点了，不需要再走一步。
*/
// @lc code=end

