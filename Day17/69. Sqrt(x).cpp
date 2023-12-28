class Solution
{
public:
    int mySqrt(int num)
    {
        int high = num, low = 0;
        while (high > low)
        {
            long int mid = low + ((long int)high - low + 1) / 2;
            if (mid <= sqrt(num))
                low = mid;
            else
                high = mid - 1;
        }
        return low;
    }
};

// solution 2
class Solution
{
public:
    long long int binarySearch(int n)
    {
        int s = 0;
        int e = n;
        int ans = -1;
        long long int mid = s + (e - s) / 2;
        while (s <= e)
        {
            long long int square = mid * mid;
            if (square == n)
                return mid;

            if (square < n)
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
    int mySqrt(int x)
    {
        return binarySearch(x);
    }
};