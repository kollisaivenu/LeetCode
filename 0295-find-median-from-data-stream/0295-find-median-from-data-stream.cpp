class MedianFinder {
public:
    priority_queue<int>smallerHeap;
    priority_queue<int, vector<int>, greater<int>>largerHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(smallerHeap.size() == 0){
            smallerHeap.push(num);
        } else if(smallerHeap.top()<=num){
            largerHeap.push(num);
            if(largerHeap.size() - smallerHeap.size() == 2){
                smallerHeap.push(largerHeap.top());
                largerHeap.pop();
            }
        } else if(num < smallerHeap.top()){
            smallerHeap.push(num);
            if(smallerHeap.size() - largerHeap.size() == 2){
                largerHeap.push(smallerHeap.top());
                smallerHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if(smallerHeap.size() == largerHeap.size()){
            return ((double)smallerHeap.top()+largerHeap.top())/2;
        } else if(smallerHeap.size()>largerHeap.size()){
            return (double)smallerHeap.top();
        } else {
            return (double)largerHeap.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */