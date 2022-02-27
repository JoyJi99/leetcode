/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:    
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
        while(i >= 0 || j >= 0){
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            int tmp = n1 + n2 + carry;
            carry = tmp / 10;
            res += to_string(tmp % 10);
            i--; j--;
        }
        if(carry == 1) res += "1";
        reverse(res.begin(), res.end());
        return res;
    }
};
/*
class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        string res = "";
        if (len2 > len1) {
            swap(len1, len2);
            swap(num1, num2);
        }
        int flag = 0; 
        for (int i = len1 - 1, j = len2 - 1; i >= 0; i--, j--) {
            int temp;
            if (j >= 0) temp = num1[i] - '0' + num2[j] - '0';
            else temp = num1[i] - '0'; 
            if (temp < 10) {
                if (flag == 0) res.insert(res.begin(), (char)(temp + '0'));
                else {
                    if (temp == 9) {
                        res.insert(res.begin(), (char)(0 + '0'));
                        flag = 1;
                    }
                    else {
                        res.insert(res.begin(), (char)(temp + 1 + '0'));
                        flag = 0;
                    }
                }  
            }
            else {
                if (flag == 0) res.insert(res.begin(), to_string(temp)[1]);
                else res.insert(res.begin(), to_string(temp + 1)[1]); 
                flag = 1; 
            } 
        }
        if (flag == 1) res.insert(res.begin(), '1');
        return res;
    }
};
*/
// @lc code=end

