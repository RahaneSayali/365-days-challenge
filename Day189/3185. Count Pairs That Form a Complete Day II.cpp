class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
    unordered_map<int, int> freq;
    long long pairs = 0;
    
    for (int h : hours) {
        int remainder = h % 24;
        int complement = (24 - remainder) % 24;
        
        pairs += freq[complement];
        freq[remainder]++;
    }
    
    return pairs;
    }
};