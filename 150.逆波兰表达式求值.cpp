/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") s.push(stoi(tokens[i]));
            else {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                if (tokens[i] == "+") s.push(num1 + num2);
                if (tokens[i] == "-") s.push(num2 - num1);
                if (tokens[i] == "*") s.push(num1 * num2);
                if (tokens[i] == "/") s.push(num2 / num1); 
            } 
        }
        return s.top();
    }
};
// @lc code=end

