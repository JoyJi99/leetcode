/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public://归并
    void merge(vector<int>& aux, vector<int>& nums, int lo, int mid, int hi){
        //copy
        for (int k = lo; k <= hi; k++) {
            aux[k] = nums[k];
        }
        //merge
        int i = lo, j = mid+1;
        for (int m = lo; m <= hi ; m++) {
            if(i > mid) nums[m] = aux[j++];//如果i走到边界，说明左边子数组已经全部移上去了，就把j移上去
            else if(j > hi) nums[m] = aux[i++];//如果j走到边界，说明右边子数组已经全部移上去了，就把i移上去
            else if(aux[j] < aux[i]) nums[m] = aux[j++];//将j移到原数组，然后j自增
            else nums[m] = aux[i++];//将i移到原数组，然后i自增
        }
    }  

    void mergeSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> aux(n);
        for (int sz = 1; sz < n; sz = sz + sz) {//外循环：子数组长度每轮翻倍
            //内循环：每个子数组归并
            for (int lo = 0; lo < n - sz; lo += sz + sz) { //sz为子数组大小  lo = lo+sz+sz 跳到下一个子数组起始位置
                merge(aux, nums, lo, lo + sz - 1, min(lo + sz + sz - 1, n - 1)); //最末子数组也许长度不够sz，长度不够则选数组最后一个元素
            }
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums);
        return nums; 
    }
};

/*
快排
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
*/
// @lc code=end

