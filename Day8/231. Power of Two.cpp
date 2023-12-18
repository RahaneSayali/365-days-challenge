// -231 <= n <= 231 - 1
// brute force
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        for (int i = 0; i <= 30; i++)
        {
            int ans = pow(2, i);
            if (ans == n)
            {
                return true;
            }
        }
        return false;
    }
};

// optimized sol
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        int ans = 1;
        for (int i = 0; i <= 30; i++)
        {
            int ans = pow(2, i);
            if (ans == n)
            {
                return true;
            }
            if (ans < INT_MAX / 2)
                ans = ans * 2;
        }
        return false;
    }
};