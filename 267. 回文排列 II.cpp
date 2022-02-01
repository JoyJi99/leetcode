class Solution {
public:
    unordered_map<char, int> char_freq;
    vector<string> res;
    void backtracking(string cur, int n){
        if (cur.size() > n) return; //加上这句快很多，不知道为啥
        if (cur.size() == n) res.push_back(cur);
        for (auto [c, freq] : char_freq){
            if (freq > 0){
                char_freq[c] -= 2;
                backtracking(c + cur + c, n);
                char_freq[c] += 2; //回溯，回溯都有一个visited或者count来加加减减
            }
        }
    }
    vector<string> generatePalindromes(string s) {
        int n = s.size();
        for (auto c: s){
            if(char_freq.count(c) != 0) char_freq[c]++;
            else char_freq[c] = 1;
        }
        int odd_cnt = 0; //出现次数为奇数的字母个数
        char odd_char;
        for (auto [c, freq]: char_freq) {
            if (freq % 2 == 1) {
                odd_cnt++;
                odd_char = c;
                if(odd_cnt > 1) return {};//最多允许一个字母出现奇数次，到时候把它放中间
            }
        }
        string mid = "";
        if (odd_cnt == 1) { //如果有一个出现奇数次的，把它放中间
            mid += odd_char;
            char_freq[odd_char]--;
        }
        backtracking(mid, n);
        return res;
    }
};

/*
1.要想回文串，最多一个字母出现奇数次且构造时把它放中间
2.所以先中间，后两边
3.排列组合，且有count或者visited
*/

/*
最后一个test case超时 "aabbccddeeffgghh"
class Solution {
private:
    vector<string> res;
    string temp;
    bool isPalin(string word){
        int tail = word.size() - 1;
        for(int i = 0, j = tail; i < j; i++, j--){
            if(word[i] != word[j]) return false;
        }
        return true;
    }
    void backtracking(string s, vector<bool>& used){
        if(temp.size() == s.size()){
            if(isPalin(temp)) res.push_back(temp);
        }
        for(int i = 0; i < s.size(); i++){
            if(used[i]) continue;
            if(i - 1 >= 0 && s[i] == s[i - 1] && used[i - 1] == false) continue;
            temp += s[i];
            used[i] = true;
            backtracking(s, used);
            used[i] = false;
            temp.pop_back();
        }
    }        
public:
    vector<string> generatePalindromes(string s) {
        vector<bool> used(s.size(), false);
        sort(s.begin(),s.end());
        backtracking(s, used);
        return res;
    }
};
*/
