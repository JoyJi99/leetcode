/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
class LRUCache {
public:
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int> >::iterator> m;
    int size;
    LRUCache(int capacity) {
        size = capacity;
    }
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        l.splice(l.begin(), l, m[key]); //splice() function here takes the element at the m[key] and places it at the beginning of the list
        return m[key]->second;
    }
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            l.splice(l.begin(), l, m[key]);
            m[key]->second = value;
            return;
        }
        if(l.size() == size) {
            auto d_key = l.back().first;
            l.pop_back();//list要删掉
            m.erase(d_key);//map里也要删掉
        }
        l.push_front({key, value});
        m[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

