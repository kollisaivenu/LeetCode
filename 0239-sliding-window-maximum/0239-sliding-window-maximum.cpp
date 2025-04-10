class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int highest = INT_MIN, second_highest = INT_MIN, indexOfHighest = -1;
        priority_queue<pair<int, int>>pq;
        for(int i=0;i<k && i<nums.size();i++){
            pq.push(make_pair(nums[i], i));
        }

        vector<int>ans;
        vector<int>done(nums.size(), false);
        int end = k;
        int start = 0;
        while(end<nums.size()){
            while(done[pq.top().second]){
                pq.pop();
            }
            ans.push_back(pq.top().first);
            done[start] = true;
            pq.push(make_pair(nums[end], end));
            end++;
            start++;
        }

        while(done[pq.top().second]){
            pq.pop();
        }
        ans.push_back(pq.top().first);
        return ans;
    }
};