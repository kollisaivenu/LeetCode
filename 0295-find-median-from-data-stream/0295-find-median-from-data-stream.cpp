class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>>minheap;
    priority_queue<int>maxheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minheap.size() == maxheap.size()) {
            if(!minheap.empty() && minheap.top() < num) {
                minheap.push(num);
            } else {
                maxheap.push(num);
            }
        } else if(minheap.size() > maxheap.size()) {
            if(num >= minheap.top()) {
                minheap.push(num);
                maxheap.push(minheap.top());
                minheap.pop();
            } else {
                maxheap.push(num);
            }
        } else {
            if(num >= maxheap.top()) {
                minheap.push(num);
            } else {
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(num);
            }
        }
        
    }
    
    double findMedian() {
        if(minheap.size() == maxheap.size()) {
            return (double(minheap.top()) + double(maxheap.top()))/2;
        } else if(minheap.size() > maxheap.size()) {
            return (double)minheap.top();
        } else {
            return (double)maxheap.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */