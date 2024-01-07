#define ll long long int
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        // dp[i][diff]+=dp[i][diff] +1 j<i  diff =nums[i]-nums[j]

        int n = nums.size();
        // key = diff*2000+i
        unordered_map<ll, ll> subscount;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                ll diff = nums[i] * 1l - nums[j] * 1l;
                ll KeyCurr = diff * 2000 + i;
                ll KeyPrev = diff * 2000 + j;
                subscount[KeyCurr] += subscount[KeyPrev] + 1;
            }
        }
        ll total = 0;
        for (auto itr = subscount.begin(); itr != subscount.end(); itr++)
        {
            total += itr->second;
        }
        // o(n*n)
        return (int)(total - (n * (n - 1)) / 2);
    }
};