class Solution {
public:

     int largestLocalUtil(std::vector<std::vector<int>>& grid, int x, int y) {
        int max = 0;
        
        for (int i = x ; i < x+3 ; i++) {
            for (int j = y ; j < y+3 ; j++) {
                max = std::max(max, grid[i][j]);
            }
        }
        
        return max;
    }
    
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
         int n = grid.size();
        
        int m = n-2;
        
        std::vector<std::vector<int>> ans(m, std::vector<int>(m, 0));
        
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < m ; j++) {
                ans[i][j] = largestLocalUtil(grid, i, j);
            }
        }
        
        return ans;
    }
};