class NumArray {
public:
    vector<int>prefixSum;
    NumArray(vector<int>& nums) {
        this->prefixSum.resize(nums.size()+1, 0);

        for(int i=0;i<nums.size();i++){
            this->prefixSum[i+1] = nums[i] + this->prefixSum[i];
        }  
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right+1] - prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */