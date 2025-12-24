class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int apples = 0;

        for(int i=0;i<apple.size();i++) {
            apples += apple[i];
        }
        int totalCapacity = 0, boxes = 0;
        sort(capacity.begin(), capacity.end());

        for(int i=capacity.size()-1;i>=0;i--) {
            totalCapacity += capacity[i];
            boxes++;
            if(totalCapacity >= apples) {
                break;
            }
        }
        return boxes;
    }
};