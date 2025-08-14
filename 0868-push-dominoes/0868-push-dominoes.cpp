#include <string>
#include <algorithm> // Required for std::fill

class Solution {
public:
    string pushDominoes(string dominoes) {
        // Add guards to handle edge cases cleanly
        string s = 'L' + dominoes + 'R';
        int lastIndex = 0;

        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == '.') {
                continue; // Skip dots until we find a non-dot
            }

            // A segment is found between s[lastIndex] and s[i]
            int count = i - lastIndex - 1; // Number of dots in the segment

            if (s[lastIndex] == 'L' && s[i] == 'L') {
                // Case: L....L -> LLLLLL
                std::fill(s.begin() + lastIndex + 1, s.begin() + i, 'L');
            } else if (s[lastIndex] == 'R' && s[i] == 'R') {
                // Case: R....R -> RRRRRR
                std::fill(s.begin() + lastIndex + 1, s.begin() + i, 'R');
            } else if (s[lastIndex] == 'R' && s[i] == 'L') {
                // Case: R....L -> RRR.LLL
                int half = count / 2;
                std::fill(s.begin() + lastIndex + 1, s.begin() + lastIndex + 1 + half, 'R');
                std::fill(s.begin() + i - half, s.begin() + i, 'L');
            }
            // Case L....R is implicitly handled, as dots remain unchanged.

            lastIndex = i; // Move to the start of the next segment
        }

        // Return the substring without the guards
        return s.substr(1, dominoes.length());
    }
};