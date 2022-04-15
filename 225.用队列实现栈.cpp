/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

/*
class MyStack {
private:
    queue<int> q1, q2; //q2是辅助队列
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int res; 
        if (q1.empty()) {
            while(q2.size() != 1) {
                q1.push(q2.front());
                q2.pop();
            }
            res = q2.front();
            q2.pop();
        }
        else {
            while(q1.size() != 1) {
                q2.push(q1.front());
                q1.pop();
            }
            res = q1.front();
            q1.pop();
        }  
        return res;
    }
    
    int top() {
        if (q1.empty()) {
            return q2.back();
        }
        else {
            return q1.back();
        } 
    }
    
    bool empty() {
        if (q1.empty() && q2.empty()) return true;
        else return false;
    }
};
*/
