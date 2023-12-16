class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int prod = 1;
        int sum = 0;
        while (n != 0)
        {
            int digit = n % 10; /* using mod we get last digit*/
            // eg 234
            // p=1*4=4
            prod = prod * digit;
            // s=0+4=4
            sum = sum + digit;
            // next n=23 ----loop will continue till n=0
            n = n / 10;
        }
        int ans = prod - sum;
        return ans;
    }
};