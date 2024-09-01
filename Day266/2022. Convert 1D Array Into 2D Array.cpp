class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& arr1D, int rows, int cols) {
        
        vector<vector<int>> arr2D(rows, vector<int>(cols));

        // Check if the total elements in the 1D array match 
        if (rows * cols != arr1D.size()) {
            return {};  // if the dimensions don't match
        }

        // Fill the 2D array with elements from the 1D array
        for (int i = 0; i < rows; i++) {        
            for (int j = 0; j < cols; j++) {    
                // Calculate correct index, assign the value to the 2D array
                arr2D[i][j] = arr1D[i * cols + j];
            }
        }

        
        return arr2D;
    }
};