class Solution {
public:
    static bool cmp(int a,int b){
        int count_a = 0,count_b = 0,temp_a = a,temp_b = b;
        while(a){
            if((a&1) == 1){
                count_a++;
            }
            a=a>>1;
        }
        while(b){
            if((b&1) == 1){
                count_b++;
            }
            b=b>>1;
        }
        if(count_a == count_b){
            return temp_a < temp_b;
        }
        return count_a < count_b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
        
    }
};