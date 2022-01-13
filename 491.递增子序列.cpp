/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    void backtracking(vector<int>& nums, int start){
        if(temp.size() > 1){
            res.push_back(temp);
        }
        set<int> uset;//只负责本层，下一层新建
        for(int i = start; i < nums.size(); i++){              
            if(!temp.empty() && nums[i] < temp.back()) continue;    
            if(uset.find(nums[i]) == uset.end()){//同一父节点下同层上使用过的元素不能再用
                temp.push_back(nums[i]);
                uset.insert(nums[i]);
            } 
            else continue;           
            backtracking(nums, i+1);
            temp.pop_back();           
        }
    }       
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {        
        backtracking(nums, 0);
        return res;
    }
};
// @lc code=end

