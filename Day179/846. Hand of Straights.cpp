class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        // Step 1: Check if grouping is possible
        if (hand.size() % groupSize != 0) {
            return false;
        }

        // Step 2: Count the occurrences of each card
        unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        // Step 3: Sort the unique card values
        vector<int> sortedKeys;
        for (auto& pair : count) {
            sortedKeys.push_back(pair.first);
        }
        sort(sortedKeys.begin(), sortedKeys.end());

        // Step 4: Form consecutive groups
        for (int key : sortedKeys) {
            if (count[key] > 0) {  // If this card is still available
                int startCount = count[key];
                // Check and form a group starting from `key`
                for (int i = key; i < key + groupSize; i++) {
                    if (count[i] < startCount) {
                        return false;
                    }
                    count[i] -= startCount;
                }
            }
        }

        // Step 5: Return true if all groups are formed successfully
        return true;
    }
};