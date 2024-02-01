class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> temp(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {

            temp[(i + k) % nums.size()] = nums[i]; // k=3
                                                   //[arr(i+k)%n]=arr[i] created formula
        }
        nums = temp;
    }
};

//we created temp to avoid overwrite
// temp[(i + k) % nums.size()] = nums[i]