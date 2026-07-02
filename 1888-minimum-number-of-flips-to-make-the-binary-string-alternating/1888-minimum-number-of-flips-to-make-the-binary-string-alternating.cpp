class Solution {
public:
    int minFlips(string s) {
        vector<int>s1(s.length()*2, 0);
        vector<int>s2(s.length()*2, 0);
        vector<int>s3(s.length()*2, 0);
        for(int i=0;i<2*s.length();i++) {
            s1[i] = s[i%s.length()] - '0';
        }

        int curr = 0;
        for(int i=0;i<s2.size();i++) {
            s2[i] = curr;
            curr = 1 - curr;
        }
        curr = 1;
        for(int i=0;i<s3.size();i++) {
            s3[i] = curr;
            curr = 1 - curr;
        }

        int left = 0, right = s.length()-1;
        int count = 0;
        int ans = INT_MAX;
        for(int i=0;i<=right;i++) {
            if(s1[i] != s2[i]) {
                count++;
            }
        }

        ans = min(ans, count);
        right++;
        for(;right<s2.size();left++, right++) {
            if(s1[left] != s2[left]) {
                count--;
            }
            if(s1[right] != s2[right]) {
                count++;
            }
            ans = min(ans, count);
        }

        // =============================
        count = 0;
        left = 0, right = s.length()-1;
        for(int i=0;i<=right;i++) {
            if(s1[i] != s3[i]) {
                count++;
            }
        }

        ans = min(ans, count);
        right++;
        for(;right<s3.size();left++, right++) {
            if(s1[left] != s3[left]) {
                count--;
            }
            if(s1[right] != s3[right]) {
                count++;
            }
            ans = min(ans, count);
        }

        return ans;
    }
};