// 1. Find the length of the array.
// 2: Find actual sum.
// 3: Find given sum.
// 4: Subtract and return.
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size(); // find length of array

        long actualSum = n * (n + 1) / 2; // formula to find total sum

        long sum = 0;
        for (int element : nums)  //sum of given no.
        {
            sum += element;
        }
        return int(actualSum - sum); //subtracting 
    }
};