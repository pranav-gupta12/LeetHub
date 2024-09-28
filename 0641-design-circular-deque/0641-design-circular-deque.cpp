class MyCircularDeque {
public:
    vector<int> arr;
    int tot;
    MyCircularDeque(int k) {
        tot=k;
    }
    
    bool insertFront(int value) {
        if(arr.size()==tot) return false;
        arr.insert(arr.begin(),value);
        return true;
        
    }
    
    bool insertLast(int value) {
          if(arr.size()==tot) return false;
        arr.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(arr.size()==0) return false;
        arr.erase(arr.begin());
        return true;
    }
    
    bool deleteLast() {
         if(arr.size()==0) return false;
        arr.pop_back();
        return true;
    }
    
    int getFront() {
         if(arr.size()==0) return -1;
        return arr.front();
    }
    
    int getRear() {
          if(arr.size()==0) return -1;
        return arr.back();
    }
    
    bool isEmpty() {
          if(arr.size()==0) return true;
        return false;
    }
    
    bool isFull() {
          if(arr.size()==tot) return true;
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