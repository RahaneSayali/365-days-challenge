class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n);
        vector<int> ans(queries.size());

        // Fill prefix XOR array
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] ^ arr[i];
        }

        // Process each query
        for (int i = 0; i < queries.size(); i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            if (left == 0) {
                ans[i] = prefix[right];
            } else {
                ans[i] = prefix[right] ^ prefix[left - 1];
            }
        }

        return ans;
    }
};