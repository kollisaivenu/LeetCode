class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int>uniqueElements;

        for(int i=0;i<nums.size();i++){
            uniqueElements[nums[i]]++;
        }

        int noOfUniqueElements = uniqueElements.size();
        uniqueElements.clear();

        int i=0, j=0, count=0;

        while(j<nums.size()){
            uniqueElements[nums[j]]++;

            while(uniqueElements.size() == noOfUniqueElements){
                uniqueElements[nums[i]]--;

                if(uniqueElements[nums[i]] == 0){
                    uniqueElements.erase(nums[i]);
                }
                i++;
            }
            count += i;
            j++;
        }
        return count;   
    }
};