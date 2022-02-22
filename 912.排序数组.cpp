/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    int partition(vector<int>& nums, int lo, int hi) {
        int i = lo, j = hi + 1;
        while (true) {
            while (nums[++i] < nums[lo]) {
                if (i == hi) break; 
            }
            while (nums[--j] > nums[lo]) {
                if (j == lo) break;
            }
            if (i >= j) break;
            exch(nums, i, j);
        }
        exch(nums, lo, j);
        return j;
    }

    void exch(vector<int>& nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    void quickSort(vector<int>& nums, int lo, int hi) {
        if (hi <= lo) return;
        int j = partition(nums, lo, hi);
        quickSort(nums, lo, j-1);
        quickSort(nums, j+1, hi);
    }

    vector<int> sortArray(vector<int>& nums) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(nums.begin(), nums.end(), default_random_engine(seed));
        quickSort(nums, 0, nums.size() - 1);
        return nums; 
    }
};
// @lc code=end

