/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;//全局变量的使用
    vector<int> temp;
    void backtracking(int start, vector<int>& nums){
        res.push_back(temp);//放在上面，否则漏掉自己 
        //if(start >= nums.size()) return; //终止条件可以不加
        for(int i = start; i < nums.size(); i++){
            temp.push_back(nums[i]);
            //res.push_back(temp);//放在上面，否则漏掉自己
            backtracking(i+1, nums);
            temp.pop_back();//回溯
        }
    }    
public:
    vector<vector<int>> subsets(vector<int>& nums) {       
        backtracking(0, nums);
        //res.push_back(temp);
        return res;
    }
};
// @lc code=end

