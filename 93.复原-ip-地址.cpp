/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
private:
    vector<string> res;
    string temp;
    bool isValid(string str){
        if(str.length() > 1 && str[0] == '0') return false;
        if(atof(str.c_str()) > 255) return false;
        return true;
    }
    void backtracking(string s, int start, int end, int time){
        if(time == 4){
            string f = s.substr(start);//越界
            if(isValid(f) && !f.empty()){
                temp += f;
                res.push_back(temp);
                temp.erase(temp.end()-f.length(), temp.end());
            }
            return;                  
        }        
        for(int i = start; i < end; i++){//end越界
            string str = s.substr(start, i - start + 1);//越界
            if(!isValid(str)) continue;
            temp += str;
            temp += ".";
            time++;
            if(i+4 > s.size()){
                backtracking(s, i+1, s.size(), time);
            }
            else backtracking(s, i+1, i+4, time);
            time--;//
            temp.pop_back();
            temp.erase(temp.end()-str.length(), temp.end());
        }
    }        
public:
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 3, 1);
        return res;
    }
};
// @lc code=end

