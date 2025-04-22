class KthLargest {
public:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    int sizeOfMinHeap;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            this->maxHeap.push(nums[i]);
        }

        int j=1;
        
        while((this->maxHeap.size() > 0) && (j<=k)){
            this->minHeap.push(this->maxHeap.top());
            this->maxHeap.pop();
            j++;
        }

        this->sizeOfMinHeap = k;
    }
    
    int add(int val) {
        if(this->minHeap.size() < this->sizeOfMinHeap){
            this->minHeap.push(val);
        } else if(val<=this->minHeap.top()){
            this->maxHeap.push(val);
        } else {
            this->maxHeap.push(this->minHeap.top());
            this->minHeap.pop();
            this->minHeap.push(val);
        }

        return this->minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */