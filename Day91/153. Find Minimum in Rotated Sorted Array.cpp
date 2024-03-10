class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1;
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            // if left part is sorted:
            if (arr[low] <= arr[mid])
            {
                // keep the minimum:
                ans = min(ans, arr[low]);

                // Eliminate left half:
                low = mid + 1;
            }
            else
            { // if right part is sorted:

                // keep the minimum:
                ans = min(ans, arr[mid]);

                // Eliminate right half:
                high = mid - 1;
            }
        }
        return ans;
    }
};