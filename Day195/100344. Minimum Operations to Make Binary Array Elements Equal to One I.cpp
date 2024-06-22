class Solution {
public:
    int minOperations(vector<int>& nums) {
         int n = nums.size();
        int operations = 0;
        
        for (int i = 0; i <= n - 3; ++i) {
            if (nums[i] == 0) {
                // Flip the elements at positions i, i+1, and i+2
                nums[i] = 1 - nums[i];
                nums[i+1] = 1 - nums[i+1];
                nums[i+2] = 1 - nums[i+2];
                operations += 1;
            }
        }
        
        // Check the last two elements to ensure they are all 1
        if (nums[n-1] == 0 || nums[n-2] == 0) {
            return -1;
        }
        
        return operations;
    }
};