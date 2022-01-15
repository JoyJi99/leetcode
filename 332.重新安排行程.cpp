/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
private:
    //unordered_map<出发机场, map<到达机场, 航班次数>> targets
    unordered_map<string, map<string, int>> targets;
    bool backtracking(vector<vector<string>>& tickets, vector<string>& res) {
        if (res.size() == tickets.size() + 1) return true;
        for (pair<const string, int>& target : targets[res[res.size() - 1]]) {
            if (target.second > 0 ) { // 记录到达机场是否飞过了
                res.push_back(target.first);
                target.second--;
                if (backtracking(tickets, res)) return true;
                res.pop_back();
                target.second++;
            }
        }
        return false;
    }    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res; 
        for (const vector<string>& vec : tickets) {
            targets[vec[0]][vec[1]]++; // 记录映射关系
        }
        res.push_back("JFK"); // 起始机场
        backtracking(tickets, res);
        return res; 
    }
};
/*
不剪枝超时
class Solution {
private:
    vector<string> res;
    vector<string> temp;
    bool compare(){
        for(int i = 0; i < temp.size(); i++){
            if(temp[i] > res[i]) return false;
            if(temp[i] < res[i]) return true;
        }
        return false; 
    }
    void backtracking(vector<vector<string>>& tickets, string str, vector<bool> used){
        if(temp.size() == tickets.size() + 1) {
            if(res.empty()) res = temp;
            else{
                if(compare()) res = temp;
            }     
            return;
        }
        for(int i = 0; i < tickets.size(); i++){
            string s = str;
            if(tickets[i][0] == str && used[i] == false) {
                
                temp.push_back(tickets[i][1]); 
                str = tickets[i][1];
                used[i] = true; 
            }
            else continue;
            backtracking(tickets, str, used);
            temp.pop_back();
            str = s;
            used[i] = false; 
        }
    }    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        temp.push_back("JFK");
        vector<bool> used(tickets.size(), false);
        backtracking(tickets, "JFK", used);
        return res;
    }
};
*/
// @lc code=end

