class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long maxDiag2 = 0;
        int ansArea = 0;
        for(int i=0;i<dimensions.size();i++){
            long long diagLength2 = dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1];
            int area = dimensions[i][0]*dimensions[i][1];
            
            if(diagLength2 == maxDiag2){
                ansArea = max(ansArea, area);
            }else if(diagLength2 >= maxDiag2){
                maxDiag2 = diagLength2;
                ansArea = area;
            }
        }

        return ansArea;
        
    }
};