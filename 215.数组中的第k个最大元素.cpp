/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int partition(vector<int>& nums, int lo, int hi) {
        int i = lo, j = hi + 1;//后面要先自加或自减，所有这里要比正常大
        while (true){
            //i从左到右
            while (nums[++i] < nums[lo]){ //while条件为true的时候一直循环，false才跳出循环
                if (i == hi) break;
            }
            //j从右到左
            while (nums[lo] < nums[--j]){ //执行j=j-1前，先自减，再a[]赋值
                if (j == lo) break;
            }
            //判断i和j是否cross
            if (i >= j) break; //如果break，后面的代码将不再执行   当i或j所在与a[lo]一致时，取等号（两边都在等号处停止）
            exch(nums, i, j);
        }
        //把partition放到中间
        exch(nums, lo, j);
        return j; //现在的j就是切分点
    }

    void exch(vector<int>& nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    void quickSort(vector<int>& nums,int lo,int hi) {
        if(hi <= lo) return; //保证数组low小于high，且数组长度最小为2
        int j = partition(nums, lo, hi);
        quickSort(nums, lo, j-1);//左半部分排序
        quickSort(nums, j+1, hi);//右半部分排序
    }

    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }
};
// @lc code=end

