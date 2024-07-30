class Solution {
public:
    bool checkString(string s) {
        int aindex = -1;  // Track the last seen index of 'a'
        int bindex = 1000; // Track the first seen index of 'b', initialized to a large value
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') {
                aindex = i; // Update the last seen index of 'a'
            } else if (s[i] == 'b') {
                bindex = i; // Update the first seen index of 'b'
            }

            if (aindex > bindex) {
                return false; // If any 'a' appears after a 'b', return false
            }
        }
        return true; // If no such condition is found, return true
    }
};