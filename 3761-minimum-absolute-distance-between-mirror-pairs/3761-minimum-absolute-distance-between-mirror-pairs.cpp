class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, vector<int>>rev_index;
        vector<int>rev;
        for(int i=0;i<nums.size();i++) {
            int rev_num = reverseInt(nums[i]);
            rev.push_back(rev_num);
            rev_index[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(int i=0; i<nums.size();i++) {
            if(rev_index[rev[i]].size() == 0) {
                continue;
            }

            int index = getLargestSmall(i, rev_index[rev[i]]);

            if (index == -1) {
                if(i != rev_index[rev[i]][0]) {
                    ans = min(ans, abs(i - rev_index[rev[i]][0]));
                }
            } else if(index == rev_index[rev[i]].size()-1) {
                continue;
                // if(i != rev_index[rev[i]][index]) {
                //     ans = min(ans, abs(i - rev_index[rev[i]][index]));
                // }
            } else {
                // if(i != rev_index[rev[i]][index]) {
                //     ans = min(ans, abs(i - rev_index[rev[i]][index]));
                // }
                if(i != rev_index[rev[i]][index+1]) {
                    ans = min(ans, abs(i - rev_index[rev[i]][index+1]));
                }
            }
        }
        if(ans == INT_MAX) {
            return -1;
        }
        
        return ans;
    }

    int reverseInt(int num) {
        int n = 0;
        while(num) {
            int dig = num%10;
            n = n*10+dig;
            num = num/10;
        }

        return n;
    }

    int getLargestSmall(int index, vector<int>&indices) {
        int low = 0, high = indices.size()-1;
        int ans = -1;
        while(low<=high) {
            int mid = low + (high-low)/2;

            if(indices[mid] <= index) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return ans;
    }
};