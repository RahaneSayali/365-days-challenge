class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> ans(nums.size()); // initiated ans array

        int even = 0, odd = 1; // two pointers for -ve +ve

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                ans[even] = nums[i], even += 2;
            else
                ans[odd] = nums[i], odd += 2;
        }
        return ans;
    }
};