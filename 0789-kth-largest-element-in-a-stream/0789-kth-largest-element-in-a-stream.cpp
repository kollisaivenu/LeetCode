class KthLargest {
public:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    int sizeOfMinHeap;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            maxHeap.push(nums[i]);
        }

        int j=1;
        
        while((maxHeap.size() > 0) && (j<=k)){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            j++;
        }

        sizeOfMinHeap = k;
    }
    
    int add(int val) {
        if(minHeap.size() < sizeOfMinHeap){
            minHeap.push(val);
        } else if(val<=minHeap.top()){
            maxHeap.push(val);
        } else {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(val);
        }

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */