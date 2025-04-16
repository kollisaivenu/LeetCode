class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>odds;
        vector<int>evens;

        for(int i=0;i<nums.size();i++){
            if(i%2 == 0){
                evens.push_back(nums[i]);
            } else {
                odds.push_back(nums[i]);
            }
        }

        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end(), greater<int>());

        vector<int>ans;
        int i=0, j=0;
        while(i<evens.size() && j<odds.size()){
            ans.push_back(evens[i]);
            ans.push_back(odds[i]);

            i++;
            j++;
        }

        if(i<evens.size()){
            ans.push_back(evens[i]);
        }

        if(j<odds.size()){
            ans.push_back(odds[i]);
        }

        return ans;
        
    }
};