class Solution {
public:
    string replaceSpace(string s) {
        int count = 0; //空格个数
        int oldSize = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') count++;
        }
        s.resize(s.size() + 2 * count); //扩充s的大小
        for (int i = s.size() - 1, j = oldSize - 1; i > j; i--, j--) {
            if (s[j] != ' ') {
                s[i] = s[j];
            } 
            else {
                s[i--] = '0';
                s[i--] = '2';
                s[i] = '%';
            }
        }
        return s;
    }
};
/*
class Solution {
public:
    string replaceSpace(string s) {
        for (int i = 0; i < s.size();) {
            if (s[i] != ' ') {
                i++;
                continue;
            }
            else {
                s.erase(i, 1);
                s.insert(i, "%20");
                i += 3;
            }
        }
        return s;
    }
};
*/
