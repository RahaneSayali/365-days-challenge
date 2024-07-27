class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long arr[26][26];
        for (int i = 0; i < 26; i++) {
            fill(arr[i], arr[i] + 26, LLONG_MAX); // Initialize with LLONG_MAX
            arr[i][i] = 0; // Cost to change a character to itself is 0
        }
        
        // Fill the transformation costs
        for (int i = 0; i < original.size(); i++) {
            int val1 = original[i] - 'a';
            int val2 = changed[i] - 'a';
            arr[val1][val2] = min(arr[val1][val2], (long long)cost[i]); // Store minimum cost
        }
        
        // Floyd-Warshall algorithm to find minimum costs between all pairs
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (arr[i][k] != LLONG_MAX && arr[k][j] != LLONG_MAX) {
                        arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                    }
                }
            }
        }
        
        long long ans = 0; // Initialize answer
        for (int i = 0; i < source.size(); i++) {
            int val1 = source[i] - 'a';
            int val2 = target[i] - 'a';

            if (val1 == val2) {
                continue; // No cost if characters are the same
            }

            if (arr[val1][val2] == LLONG_MAX) {
                return -1; // Return -1 if no valid transformation exists
            } else {
                // Check for potential overflow before adding
                if (ans > LLONG_MAX - arr[val1][val2]) {
                    return -1; // Handle potential overflow
                }
                ans += arr[val1][val2]; // Accumulate cost
            }
        }
        return ans; // Return total cost
    }
};