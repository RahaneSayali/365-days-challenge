class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;
        
        // Iterate through the array and count transitions
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1]) {
                operations++;
            }
        }
        
        // If the first element is 0, we need one additional operation
        if (nums[0] == 0) {
            operations++;
        }
        
        return operations;
    }
};