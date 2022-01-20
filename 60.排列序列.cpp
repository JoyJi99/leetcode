/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution {
private:
    string res;
    int num;
    bool isValid(int num){
        for(int i = 0; i < res.length(); i++){
            char c = num + '0';
            if(c == res[i]) return false;
        }
        return true;
    }
    bool backtracking(int n, int k){
        if(res.length() == n){
            num++;
            if(num == k) return true;
            return false;
        }
        for(int i = 1; i <= n; i++){
           if(!isValid(i)) continue; 
           res += to_string(i);
           if(backtracking(n, k)) return true;
           res.pop_back();
        }
        return false;
    }    
public:
    string getPermutation(int n, int k) {
        int prod = 1;
        for(int i = 1; i <= n; i++){
            prod *= i;
        }
        int team = prod / n;
        int start = k / team;
        if(k%team == 0) {
            res += to_string(start);
            backtracking(n, team);
        }
        else{
            res += to_string(start + 1);
            backtracking(n, k % team);
        }  
        return res;
    }
};
/*
超出时间限制
class Solution {
private:
    string res;
    int num;
    bool isValid(int num){
        for(int i = 0; i < res.length(); i++){
            char c = num + '0';
            if(c == res[i]) return false;
        }
        return true;
    }
    bool backtracking(int n, int k){
        if(res.length() == n){
            num++;
            if(num == k) return true;
            return false;
        }
        for(int i = 1; i <= n; i++){
           if(!isValid(i)) continue; 
           res += to_string(i);
           if(backtracking(n, k)) return true;
           res.pop_back();
        }
        return false;
    }    
public:
    string getPermutation(int n, int k) {
        backtracking(n, k);
        return res;
    }
};
*/
// @lc code=end

