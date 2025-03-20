class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        for(int i=s.length()-1;i>=0;i--){
            for(int j=t.length()-1;j>=0;j--){
                int currAns = 0;
                if(s[i] != t[j]){
                    int leftSubarrays = 0;
                    int goLeftI = i-1;
                    int goLeftJ = j-1;

                    while(goLeftI >=0 && goLeftJ >= 0 && s[goLeftI] == t[goLeftJ]){
                        leftSubarrays++;
                        goLeftI--;
                        goLeftJ--;
                    }

                    int rightSubarrays = 0;
                    int goRightI = i+1;
                    int goRightJ = j+1;

                    while(goRightI < s.length() && goRightJ < t.length() && s[goRightI] == t[goRightJ]){
                        rightSubarrays++;
                        goRightI++;
                        goRightJ++;
                    }
                    currAns += (1 + leftSubarrays)*(1 + rightSubarrays);
                }
                ans += currAns;

            }
        }
        return ans;   
    }
};