/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums[0] >= 0) { //全正
            if(k % 2 == 0) return accumulate(nums.begin(), nums.end(), 0);
            else return accumulate(nums.begin() + 1, nums.end(), 0) - nums[0]; 
        }
        else if (nums[nums.size() - 1] < 0) { //全负
            if(k % nums.size() == 0) return accumulate(nums.begin(), nums.end(), 0);
            if ((k / nums.size()) % 2 == 0) {
                return accumulate(nums.begin() + k % nums.size(), nums.end(), 0) - accumulate(nums.begin(), nums.begin() + k % nums.size(), 0);
            }
            else {
                return - accumulate(nums.begin(), nums.end() - k % nums.size(), 0) + accumulate(nums.end() - k % nums.size(), nums.end(), 0);
            }
        }
        else {//有正有负
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] < 0) count++;
                if (nums[i] >= 0) break;
            }
            if (k <= count) return accumulate(nums.begin() + k, nums.end(), 0) - accumulate(nums.begin(), nums.begin() + k, 0);
            else {
                for (int i = 0; i < count; i++) {
                    nums[i] = -nums[i];
                }
                sort(nums.begin(), nums.end());
                k = k - count;
                if(k % 2 == 0) return accumulate(nums.begin(), nums.end(), 0);
                else return accumulate(nums.begin() + 1, nums.end(), 0) - nums[0];  
            } 
        }
    }
};
/*
贪心解法，更简略
class Solution {
static bool cmp(int a, int b) {
    return abs(a) > abs(b);
}
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);       // 第一步，注意sort用法，按照绝对值大小从大到小排序
        for (int i = 0; i < A.size(); i++) { // 第二步
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        if (K % 2 == 1) A[A.size() - 1] *= -1; // 第三步，如果K还大于0，那么反复转变数值最小的元素，将K用完
        int result = 0;
        for (int a : A) result += a;        // 第四步
        return result;
    }
};
*/
// @lc code=end

