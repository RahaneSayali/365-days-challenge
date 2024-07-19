class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> luckyNumbers;

        for (int i = 0; i < n; i++) {
            int num = numeric_limits<int>::max();
            int index = -1;

            // Find the minimum number in the current row
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < num) {
                    num = matrix[i][j];
                    index = j;
                }
            }

            // Check if this number is the maximum in its column
            bool flag = true;
            for (int row = 0; row < n; row++) {
                if (matrix[row][index] > num) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                luckyNumbers.push_back(num);
            }
        }

        return luckyNumbers;
    }
};