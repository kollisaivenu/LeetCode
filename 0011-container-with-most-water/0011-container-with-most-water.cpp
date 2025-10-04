class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxArea = 0;
        while (left < right){
            int currentArea = min(height[left], height[right])*(right - left);
            maxArea = (currentArea > maxArea) ? currentArea : maxArea;

            if (height[left] > height[right]){
                right--;
            } else {
                left++;
            }
        }

        return maxArea;

    }   
};