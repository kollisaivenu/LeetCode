class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool>vis(arr.size(), false);
        vis[start] = true;
        return reached(arr, vis, start);
    }

    bool reached(vector<int>& arr, vector<bool>&vis, int curr) {
        if(arr[curr] == 0) {
            return true;
        }

        bool ans = false;

        if(arr[curr] + curr < arr.size() && arr[curr] + curr >= 0 && vis[arr[curr] + curr] == false) {
            vis[arr[curr] + curr] = true;
            ans = ans | reached(arr, vis, arr[curr] + curr);
        }

        if(curr - arr[curr] >= 0 && curr - arr[curr] < arr.size() && vis[curr - arr[curr]] == false) {
            vis[curr - arr[curr]] = true;
            ans = ans | reached(arr, vis, curr - arr[curr]);
        }

        return ans;
    }
};