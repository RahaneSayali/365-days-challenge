class Solution {
public:
    string clearDigits(string s) {a
         while (s.find_first_of("0123456789") != string::npos) {
        // Find the first digit in the string
        size_t digitPos = s.find_first_of("0123456789");
        
        // Find the closest non-digit character to its left
        size_t removePos = digitPos - 1;
        while (removePos != string::npos && isdigit(s[removePos])) {
            --removePos;
        }
        
        // If there is no non-digit character to the left, just remove the digit
        if (removePos == string::npos) {
            s.erase(digitPos, 1);
        } else {
            // Remove the digit and the closest non-digit character to its left
            s.erase(digitPos, 1);
            s.erase(removePos, 1);
        }
    }
    
    return s;
    }
};