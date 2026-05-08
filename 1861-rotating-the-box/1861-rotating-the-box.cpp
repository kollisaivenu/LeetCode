class Solution {
public:
    void fallDown(vector<vector<char>>& box, int i, int j){
        if(i+1 == box.size() || box[i+1][j] == '*' || box[i+1][j] == '#'){
            box[i][j] = '#';
        } else {
            fallDown(box, i+1, j);
        }

    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size();
        int cols = box[0].size();

        vector<vector<char>>newBox(cols, vector<char>(rows));

        for(int i=0;i<cols;i++){
            for(int j=0;j<rows;j++){
                newBox[i][j] = box[rows-1-j][i];
            }
        }
        for(int i=cols-1;i>=0;i--){
            for(int j=0;j<rows;j++){
                if(newBox[i][j] == '#'){
                    newBox[i][j] = '.';
                    fallDown(newBox, i, j);
                }
                
            }
        }
        return newBox;
    }
};