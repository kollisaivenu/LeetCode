class Solution {
public:
    static bool compare(vector<int>&v1, vector<int>&v2){
        if(v1[0] == v2[0]){
            return v1[1] < v2[1];
        }
        return v1[0] < v2[0];
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>lengthCoordinates;
        vector<vector<int>>heightCoordinates;
        
        for(int i=0;i<rectangles.size();i++){
            lengthCoordinates.push_back(vector<int>{rectangles[i][0], rectangles[i][2]});
            heightCoordinates.push_back(vector<int>{rectangles[i][1], rectangles[i][3]});
        }

        sort(lengthCoordinates.begin(), lengthCoordinates.end(), compare);
        sort(heightCoordinates.begin(), heightCoordinates.end(), compare);
        
        int noOfMergedLengths = 1;
        int noOfMergedHeights = 1;

        vector<int>currentLength = lengthCoordinates[0];
        for(int i=1;i<lengthCoordinates.size();i++){
            if(currentLength[1] > lengthCoordinates[i][0]){
                currentLength[1] = max(lengthCoordinates[i][1], currentLength[1]);
            } else {
                noOfMergedLengths++;

                if(noOfMergedLengths >= 3){
                    return true;
                }
                currentLength = lengthCoordinates[i];
            }
        }

        vector<int>currentHeight = heightCoordinates[0];
        for(int i=1;i<heightCoordinates.size();i++){
            if(currentHeight[1] > heightCoordinates[i][0]){
                currentHeight[1] = max(heightCoordinates[i][1], currentHeight[1]);
            } else {
                noOfMergedHeights++;
                if(noOfMergedHeights >= 3){
                    return true;
                }
                currentHeight = heightCoordinates[i];
            }
        }
        return false;
    }
};