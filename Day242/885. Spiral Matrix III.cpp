class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // East, South, West, North
        vector<vector<int>> result = {{rStart, cStart}};
        int steps = 0, d = 0;
        
        while (result.size() < rows * cols) {
            if (d == 0 || d == 2) steps++;
            
            for (int i = 0; i < steps; i++) {
                rStart += directions[d][0];
                cStart += directions[d][1];
                
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    result.push_back({rStart, cStart});
                }
                
                if (result.size() == rows * cols) return result;
            }
            
            d = (d + 1) % 4;
        }
        
        return result;
    }
};