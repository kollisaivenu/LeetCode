class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v;
        vector<int>temp;
        temp.push_back(1);
        v.push_back(temp);

        if(numRows == 1){
            return v;
        }

        vector<int> temp1;
        temp1.push_back(1);
        temp1.push_back(1);
        v.push_back(temp1);

        if(numRows == 2){
            return v;
        }

        for(int i=2;i<numRows;i++){
            vector<int> temp3(i+1);

            temp3[0] = 1;
            temp3[i] = 1;
            int j = 0, k = 1;

            for(int l=1;l<i;l++){
                temp3[l] = v[i-1][j] + v[i-1][k];
                j++;
                k++;
            }
            v.push_back(temp3);
        }

        return v;
        
    }
};