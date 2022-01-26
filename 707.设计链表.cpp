/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
private:
    struct LinkedNode{// 定义链表节点结构体
        LinkedNode * next;
        int val;
        LinkedNode(int val): val(val), next(nullptr){} 
    };
    int _size;
    LinkedNode* _dummyHead;    
public:
    MyLinkedList() {// 初始化链表
        _dummyHead = new LinkedNode(0);
        _size = 0; 
    }
    
    int get(int index) {
        if(index > _size - 1) return -1;
        LinkedNode * cur = _dummyHead; 
        for(int i = 0; i <= index; i++){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode * cur = new LinkedNode(val);
        cur->next = _dummyHead->next;
        _dummyHead->next = cur; 
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode * newNode = new LinkedNode(val);
        LinkedNode * cur = _dummyHead;
        for(int i = 0; i < _size; i++){
            cur = cur->next;
        }
        cur->next = newNode; 
        _size++;
    }
    
    void addAtIndex(int index, int val) { 
        if(index < 0){
            addAtHead(val);
            return;
        } 
        if(index > _size) return;
        if(index == _size){
            addAtTail(val);
            return; 
        } 
        LinkedNode * newNode = new LinkedNode(val);
        LinkedNode * cur = _dummyHead;
        for(int i = 0; i < index; i++){
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;        
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index > _size - 1) return;
        LinkedNode * cur = _dummyHead;
        for(int i = 0; i < index; i++){
            cur = cur->next;
        }
        LinkedNode * toDelete = cur->next;
        cur->next = toDelete->next;
        delete toDelete;
        _size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

