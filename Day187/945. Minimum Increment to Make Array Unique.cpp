class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // Sort the vector first
        std::sort(nums.begin(), nums.end());

        int numTracker = 0; // Tracks the next unique number that should be set.
        int minIncrement = 0; // Counts the total increments required.

        for (int num : nums) {
            numTracker = std::max(numTracker, num);
            minIncrement += numTracker - num;
            numTracker += 1; // Increment the tracker for the next number.
        }

        return minIncrement;
    }
};