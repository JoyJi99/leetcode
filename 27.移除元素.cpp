/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {//快慢指针法
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
        /*
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j){           
            if(nums[i] == val) {
                if(nums[j] == val) j--;
                else{
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }         
            }
            else i++;
        }
        return i;  
        */         
    }
};
// @lc code=end

