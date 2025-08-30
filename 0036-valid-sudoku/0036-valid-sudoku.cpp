#include <string.h>
#include <iostream>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        char dot = '.';
        for(int i = 0; i < 9; i++){
            vector<int> occ(10, 0);
            
            for(int j = 0; j < 9; j++){
                if (board[i][j] != dot){
                    if (occ[board[i][j] - '0'] != 0){
                        return false;
                    }
                    occ[board[i][j] - '0']++;
                }
            }  
        }
        for(int i = 0; i < 9; i++){
            vector<int> occ(10, 0);
            for(int j = 0; j < 9; j++){
                if (board[j][i] != dot){
                    if (occ[board[j][i] - '0'] != 0){
                        return false;
                    }
                    occ[board[j][i] - '0']++;
                }
            }   
        }

        for(int i=0; i < 9;i=i+3){
            for(int j=0; j < 9; j=j+3){
                vector<int> occ(10, 0);
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if (board[k][l] != dot){
                            if (occ[board[k][l] - '0'] != 0){
                                return false;
                            }
                            occ[board[k][l] - '0']++;
                        }
                    }
                } 
            }
        }
        return true;
        
    }
};