class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;

        while(k > 0){
            int noOfNumbers = countNumbers(n, curr, curr+1);

            if(noOfNumbers <= k){
                k -= noOfNumbers;
                curr++;
            } else {
                k--;
                curr *= 10;
            }
        }

        return curr;
    }

    int countNumbers(int n, long prefix1, long prefix2){
        int count = 0;

        while(prefix1 <= n){
            count += min((long)(n+1), prefix2) - prefix1;

            prefix1 *= 10;
            prefix2 *= 10;
        }

        return count;
    }
};