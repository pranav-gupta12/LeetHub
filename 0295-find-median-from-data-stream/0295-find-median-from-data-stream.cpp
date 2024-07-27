class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    double median = INT_MIN;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.size()==minheap.size()){
            if(num>median){
minheap.push(num);
                median = minheap.top();
            }
            else
            {
                maxheap.push(num);
                median = maxheap.top();
            }
        }
        else if ( maxheap.size()<minheap.size()){
            
              if(num>median){
maxheap.push(minheap.top());
                  minheap.pop();
                  minheap.push(num);
                  median = 0.5* ( minheap.top() + maxheap.top());
            }
            else
            {
                maxheap.push(num);
                  median = 0.5* ( minheap.top() + maxheap.top());
            }
        }
        else
        {
              if(num>median){
                  minheap.push(num);
 median = 0.5* ( minheap.top() + maxheap.top());
            }
            else
            {
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(num);
                 median = 0.5* ( minheap.top() + maxheap.top());
            }
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */