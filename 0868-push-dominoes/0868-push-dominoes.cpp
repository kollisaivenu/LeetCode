#include <string>
#include <algorithm>

class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = 'L' + dominoes + 'R';
        int lastIndex = 0;

        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == '.') {
                continue;
            }

            int count = i - lastIndex - 1;

            if (s[lastIndex] == 'L' && s[i] == 'L') {
                std::fill(s.begin() + lastIndex + 1, s.begin() + i, 'L');
            } else if (s[lastIndex] == 'R' && s[i] == 'R') {
                std::fill(s.begin() + lastIndex + 1, s.begin() + i, 'R');
            } else if (s[lastIndex] == 'R' && s[i] == 'L') {
                int half = count / 2;
                std::fill(s.begin() + lastIndex + 1, s.begin() + lastIndex + 1 + half, 'R');
                std::fill(s.begin() + i - half, s.begin() + i, 'L');
            }

            lastIndex = i;
        }
        return s.substr(1, dominoes.length());
    }
};