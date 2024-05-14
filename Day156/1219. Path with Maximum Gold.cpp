class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxGold = 0;

        // Helper function for DFS
        function<int(int, int)> helper = [&](int row, int col) -> int {
            if (row < 0 || row >= m || col < 0 || col >= n ||
                grid[row][col] == 0) {
                return 0;
            }

            int currentGold = grid[row][col];
            grid[row][col] = 0; // Mark the cell as visited by setting it to 0

            // Recursively explore all four directions
            int d = helper(row + 1, col);
            int u = helper(row - 1, col);
            int r = helper(row, col + 1);
            int l = helper(row, col - 1);

            // Restore the cell value
            grid[row][col] = currentGold;

            return currentGold + max({d, u, r, l});
        };

        // Iterate over all cells in the grid
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] > 0) {
                    maxGold = max(maxGold, helper(row, col));
                }
            }
        }

        return maxGold;
    }
};