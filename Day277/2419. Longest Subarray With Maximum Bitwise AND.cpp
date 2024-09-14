class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       
        int maxBitwiseAnd = *max_element(nums.begin(),nums.end());
        int maxi = 1;
        int count = 0;
        int i = 0;
        while(i < nums.size())
        {
            if(nums[i] == maxBitwiseAnd)
            {
                while(i < nums.size() and nums[i++] == maxBitwiseAnd) count++;
                maxi = max(maxi,count);
                count = 0;
            }
            else i++;
        }
        return maxi;
    }
};