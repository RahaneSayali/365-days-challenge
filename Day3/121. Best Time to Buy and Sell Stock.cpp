class Solution
{
public:
    int maxProfit(vector<int> &a)
    {
        int min_price = a[0];
        int maxprofit = 0;

        for (int i = 1; i < a.size(); i++)
        {
            maxprofit = max(maxprofit, a[i] - min_price);
            min_price = min(a[i], min_price);
        }
        return maxprofit;
    }
};