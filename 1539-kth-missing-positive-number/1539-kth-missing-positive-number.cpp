class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1;
        int index = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;

            if(arr[mid] - mid - 1 < k) {
                index = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if(index == -1) {
            return k;
        }
        return arr[index] + k - (arr[index] - index - 1);  
    }
};