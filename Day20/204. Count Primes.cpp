class Solution
{
public:
    int countPrimes(int n)
    {
        bool prime[n + 1];
        if (n == 0 || n == 1)
            return 0;
        prime[0] = prime[1] = false;
        memset(prime, true, sizeof(prime));
        for (int i = 2; i * i < n; i++)
        {
            if (prime[i] == true)
            {
                for (int j = i * i; j < n; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        vector<int> res;
        for (int i = 2; i < n; i++)
        {
            if (prime[i] == true)
                res.push_back(i);
        }
        return res.size();
    }
};