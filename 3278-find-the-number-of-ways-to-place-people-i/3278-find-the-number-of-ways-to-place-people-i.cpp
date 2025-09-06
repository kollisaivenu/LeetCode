class Solution {
public:
    
    int numberOfPairs(vector<vector<int>>& points) {
        int no = points.size();
        int count = 0;

        for(int i=0;i<no;i++){
            for(int j=0;j<no;j++){
                if(i != j){
                    if(points[i][1] >= points[j][1] && points[i][0] <= points[j][0]){
                        bool flag = true;
                        for(int k=0;k<no;k++){
                            if(k != i && k != j){
                                int x = points[k][0];
                                int y = points[k][1];

                                if((y <= points[i][1] && y >= points[j][1]) && (x >= points[i][0] && x <= points[j][0])){
                                    flag = false;
                                    break;
                                }
                            }
                        }

                        if(flag){
                            count++;
                        }
                    }
                }
            }
        }

        return count;

    }
};