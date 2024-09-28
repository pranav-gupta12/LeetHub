class MyCircularDeque {
public:
    int curr_size;
    int max_size;
    deque<int> que;
    MyCircularDeque(int k) {
        
         max_size=k;
         curr_size = 0;
    }
    
    bool insertFront(int value) {
        if(curr_size>=max_size) return false;
        que.push_front(value);
        curr_size++;
        return true;
        
    }
    
    bool insertLast(int value) {
         if(curr_size>=max_size) return false;
         que.push_back(value);
        curr_size++;
        return true;
    }
    
    bool deleteFront() {
        if(curr_size==0) return false;
        que.pop_front();
        curr_size--;
        return true;
    }
    
    bool deleteLast() {
          if(curr_size==0) return false;
        que.pop_back();
        curr_size--;
        return true;
    }
    
    int getFront() {
            if(curr_size==0) return -1;
        return que.front();
    }
    
    int getRear() {
           if(curr_size==0) return -1;
        return que.back();
    }
    
    bool isEmpty() {
        return que.empty();
    }
    
    bool isFull() {
        if(curr_size==max_size) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */