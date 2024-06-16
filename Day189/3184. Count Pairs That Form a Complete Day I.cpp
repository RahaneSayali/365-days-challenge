class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> remainderCount;
    int count = 0;

    for (int hour : hours) {
        int remainder = hour % 24;
        int complement = (24 - remainder) % 24; // complement to form a multiple of 24
        
        if (remainderCount.find(complement) != remainderCount.end()) {
            count += remainderCount[complement];
        }
        
        remainderCount[remainder]++;
    }

    return count;
    }
};