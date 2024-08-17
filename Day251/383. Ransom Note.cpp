class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> charCount(26, 0);
    // Count the frequency of each ch
    for (char c : magazine) {
        charCount[c - 'a']++;
    }

    // Check if ransomNote can be constructed
    for (char c : ransomNote) {
        if (charCount[c - 'a'] == 0) {
            return false;  // Not enough of this ch
        }
        charCount[c - 'a']--;
    }

    return true;
    }
};