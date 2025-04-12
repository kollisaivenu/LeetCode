class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_map<int, int>freq;
        unordered_map<string, bool>alreadySeen;
        vector<long long>fact(11, 1);
        for(int i=1;i<=10;i++){
            fact[i] = i*fact[i-1];
        }
        long long count = 0;
        palindromes("", n, k, count, freq, alreadySeen, fact);
        return count;
    }

    void palindromes(string num, int n, int& k, long long &count, unordered_map<int, int>&freq, unordered_map<string, bool>&alreadySeen, vector<long long>&fact){
        if(n == 0){
            long long number = stoll(num);
            string toSort = num;
            sort(toSort.begin(), toSort.end());
            if(number%k == 0 && alreadySeen[toSort] == false){
                alreadySeen[toSort] = true;
                long long numOfCombos = (num.length()-freq[0])*fact[num.length()-1];
                for(int i=0;i<=9;i++){
                    numOfCombos = numOfCombos/fact[freq[i]];
                }
                count += numOfCombos;
            }
            return;
        }
        if(n == 1){
            for(int i=1;i<=9;i++){
                freq[i] = freq[i] + 1;
                palindromes(to_string(i), n-1, k, count, freq, alreadySeen, fact);
                freq[i] = freq[i] - 1;
            }
            return;

        }
        if(n%2 == 1){
            for(int i=0;i<=9;i++){
                freq[i] = freq[i] + 1;
                palindromes(to_string(i), n-1, k, count, freq, alreadySeen, fact);
                freq[i] = freq[i] - 1;
            }
            return;
        }

        if(n == 2){
            for(int i=1;i<=9;i++){
                freq[i] = freq[i] + 2;
                palindromes(to_string(i) + num + to_string(i), n-2, k, count, freq, alreadySeen, fact);
                freq[i] = freq[i] - 2;
            }
        } else {
            for(int i=0;i<=9;i++){
                freq[i] = freq[i] + 2;
                palindromes(to_string(i) + num + to_string(i), n-2, k, count, freq, alreadySeen, fact);
                freq[i] = freq[i] - 2;
            }
        }
    }
};