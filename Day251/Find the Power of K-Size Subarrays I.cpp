class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
          int n = nums.size();
    vector<int> results(n - k + 1, -1); // Initialize results with -1

    for (int i = 0; i <= n - k; i++) {
        bool isConsecutive = true;

        // Check if the elements in the subarray are consecutive and sorted
        for (int j = 1; j < k; j++) {
            if (nums[i + j] - nums[i + j - 1] != 1) {
                isConsecutive = false;
                break;
            }
        }

        if (isConsecutive) {
            results[i] = nums[i + k - 1]; // The maximum element of the subarray is the last one if they are consecutive
        }
    }

    return results;
    }
};