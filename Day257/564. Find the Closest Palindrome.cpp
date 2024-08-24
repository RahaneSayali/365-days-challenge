class Solution {
public:
    string nearestPalindromic(string n) {
        int length = n.size();
        set<string> candidates;

        // Edge cases
        if (n == "1") return "0";

        // Create the prefix
        string prefix = n.substr(0, (length + 1) / 2);
        long long prefixNumber = stoll(prefix);

        // Generate candidates
        for (long long i : {-1, 0, 1}) {
            string newPrefix = to_string(prefixNumber + i);
            string candidate;
            if (length % 2 == 0) {
                candidate = newPrefix + string(newPrefix.rbegin(), newPrefix.rend());
            } else {
                candidate = newPrefix + string(newPrefix.rbegin() + 1, newPrefix.rend());
            }
            candidates.insert(candidate);
        }

        // Edge cases for smallest and largest palindromes
        candidates.insert(to_string(static_cast<long long>(pow(10, length - 1)) - 1));
        candidates.insert(to_string(static_cast<long long>(pow(10, length)) + 1));

        // Remove the original number from candidates
        candidates.erase(n);

        // Find the closest palindrome
        string closestPalindrome;
        long long minDifference = LLONG_MAX;
        long long num = stoll(n);
        for (const string& candidate : candidates) {
            long long candidateNum = stoll(candidate);
            long long difference = abs(candidateNum - num);
            if (difference < minDifference || (difference == minDifference && candidateNum < stoll(closestPalindrome))) {
                minDifference = difference;
                closestPalindrome = candidate;
            }
        }

        return closestPalindrome;
    }
};