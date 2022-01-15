/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size() - 1;
        vector<int> res(nums.size(), -1);
        for(int i = 0, j = nums.size() - 1; i <= j;){
            if(nums[i]*nums[i] > nums[j]*nums[j]){
                res[k--] = nums[i]*nums[i];
                i++; 
            }
            else{
                res[k--] = nums[j]*nums[j];
                j--;
            }
        }
        return res; 
    }
};
/*
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());//快速排序 
        return nums; 
    }
};
*/
// @lc code=end

