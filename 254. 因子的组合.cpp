class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    void backtracking(int n, int start, int final){
        if(n == 1){
            if(!temp.empty() && temp[0] == final) return;
            res.push_back(temp);
            return;
        }
        for(int i = start; i <= n; i++){
            if(n % i != 0) continue;
            temp.push_back(i);
            int pre = n;
            n = n / i;
            backtracking(n, i, final);
            n = pre;
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> getFactors(int n) {
        if(n == 1) return res;
        backtracking(n, 2, n);
        return res;
    }
};
