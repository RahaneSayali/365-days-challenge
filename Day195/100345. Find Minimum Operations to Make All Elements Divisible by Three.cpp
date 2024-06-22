class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         int operations = 0;

        for (int num : nums) {
            int remainder = num % 3;
            if (remainder == 1) {
                operations += 1;  // Subtract 1 or add 2 (1 operation)
            } else if (remainder == 2) {
                operations += 1;  // Subtract 2 or add 1 (1 operation)
            }
        }

        return operations;
    }
};