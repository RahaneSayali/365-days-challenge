class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        int mask = 0, maxLength = 0;
        unordered_map<int,int> m;
        m[0] = -1;
        
        for (int i = 0; i < n; i++) {

            if (s[i] == 'a') mask ^= (1 << 0);
            else if (s[i] == 'e') mask ^= (1 << 1);
            else if (s[i] == 'i') mask ^= (1 << 2);
            else if (s[i] == 'o') mask ^= (1 << 3);
            else if (s[i] == 'u') mask ^= (1 << 4);
            
            if (m.find(mask) != m.end()) {
                maxLength = max(maxLength, i  - m[mask]);
            } else {
                m[mask] = i;
            }
        }
        return maxLength;
    }
};