class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long noOfZeroesInNums1 = 0, noOfZeroesInNums2 = 0,sumOfNums1 = 0, sumOfNums2 = 0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i] > 0){
                sumOfNums1 += nums1[i];
            } else {
                noOfZeroesInNums1++;
            }
            
        }

        for(int i=0;i<nums2.size();i++){
            if(nums2[i] > 0){
                sumOfNums2 += nums2[i];
            } else {
                noOfZeroesInNums2++;
            }
        }
        cout<<sumOfNums1 + noOfZeroesInNums1<<"\n";
        cout<<sumOfNums2 + noOfZeroesInNums2<<"\n";
        if(sumOfNums1 + noOfZeroesInNums1 >= sumOfNums2 + noOfZeroesInNums2){
            if((noOfZeroesInNums2 > 0) || (sumOfNums1 + noOfZeroesInNums1 == sumOfNums2)){
                return sumOfNums1 + noOfZeroesInNums1;
            } else {
                return -1;
            }
        } else {
            if(noOfZeroesInNums1 > 0 || (sumOfNums2 + noOfZeroesInNums2 == sumOfNums1)){
                return sumOfNums2 + noOfZeroesInNums2;
            } else {
                return -1;
            }
        }
    
    }
};