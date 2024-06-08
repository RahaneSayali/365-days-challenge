class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 1));
    int result = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            for (int t = 0; t <= k; ++t) {
                if (nums[i] != nums[j] && t + 1 <= k) {
                    dp[i][t + 1] = max(dp[i][t + 1], dp[j][t] + 1);
                    result = max(result, dp[i][t + 1]);
                } else if (nums[i] == nums[j]) {
                    dp[i][t] = max(dp[i][t], dp[j][t] + 1);
                    result = max(result, dp[i][t]);
                }
            }
        }
    }
    return result;
    }
};