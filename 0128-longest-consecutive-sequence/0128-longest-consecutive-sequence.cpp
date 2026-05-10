class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool>isPresent;
        unordered_map<int, int>visited;

        for(int i=0;i<nums.size();i++) {
            isPresent[nums[i]] = true;
        }

        int ans = 0;

        for(int i=0;i<nums.size();i++) {
            int count = 1;
            int mid = nums[i];
            if(!visited[mid]) {
                visited[mid] = true;
                int backward = mid-1;
                while(isPresent[backward]) {
                    count++;
                    visited[backward] = true;
                    backward--;
                }
                int forward = mid+1;
                while(isPresent[forward]) {
                    count++;
                    visited[forward] = true;
                    forward++;
                }
                
            }
            

            ans = max(ans, count);
        }

        return ans;
    }
};