/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
struct Trie{
	Trie* child[26];
	string t = "";
	Trie() {
		for (int i = 0; i < 26; i++)
			child[i] = nullptr;
	}
};
class Solution {
public:
	vector<string> res;
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		Trie* t = new Trie();
		//创建前缀树，将words中所有单词加入前缀树
		for (int i = 0; i < words.size(); i++){
			Trie* cur = t;
			for (int j = 0; j < words[i].size(); j++){
				if (cur->child[words[i][j] - 'a'] == nullptr) cur->child[words[i][j] - 'a'] = new Trie();
				cur = cur->child[words[i][j] - 'a'];
			}
			cur->word = words[i];
		}
		for (int i = 0; i < board.size(); i++){
			for (int j = 0; j < board[i].size(); j++){
				dfs(board, t, i, j);	
			}
		}
		return res;
	}
	void dfs(vector<vector<char>>& board, Trie* t,int i ,int j){
		if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;
		char c = board[i][j];
		if (c == '*' || t->child[c-'a']==nullptr) return;
		t = t->child[c - 'a'];
		if (t->word != "") {
			res.push_back(t->word);
			t->word = "";
		}
		board[i][j] = '*';
		dfs(board, t, i + 1, j);
		dfs(board, t, i - 1, j);
		dfs(board, t, i, j + 1);
		dfs(board, t, i, j - 1);
		board[i][j] = c;
		return;	
	}
};
/**
 超时
class Solution {
private:
    vector<string> res;
    vector<pair<pair<int, int>, char>> coor;
    bool backtracking(int r, int c, vector<vector<char>>& board, string& word){
        if(!word.length()) return true;//word为空
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[0]) return false;
        string str = word.substr(1);
        char ori = board[r][c];
        board[r][c] = '*';
        coor.push_back(make_pair(make_pair(r, c), ori));
        if(backtracking(r + 1, c, board, str) || backtracking(r - 1, c, board, str) || backtracking(r, c + 1, board, str) || backtracking(r, c - 1, board, str)) return true;
        coor.pop_back();
        board[r][c] = ori;
        return false;
    }
    void recover(vector<vector<char>>& board, string word){//有问题
        for(int i = 0; i < coor.size(); i++){
            int r = coor[i].first.first;
            int c = coor[i].first.second;
            board[r][c] = coor[i].second;          
        } 
    }
    void findWordsHelper(vector<vector<char>>& board, vector<string>& words){
        bool nFind = true;
        for(int i = 0; i < words.size(); i++){
            for(int r = 0; r < board.size() && nFind; r++){
                for(int c = 0; c < board[0].size() && nFind; c++){
                    if(backtracking(r, c, board, words[i])){
                        res.push_back(words[i]);
                        recover(board, words[i]);
                        nFind = false;
                    } 
                }
            }
            nFind = true;    
        }
    }        
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        findWordsHelper(board, words);
        return res;
    }
}; 
 */
// @lc code=end

