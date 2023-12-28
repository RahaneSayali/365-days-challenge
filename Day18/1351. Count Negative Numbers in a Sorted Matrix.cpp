class Solution
{
public:
    int countNegatives(vector<vector<int>> &n)
    {
        int count = 0;

        for (int i = 0; i < n.size(); i++)
        {
            int e = 0;
            int s = n[i].size() - 1;
            int mid = e + (s - e) / 2;
            int ans = -1;

            while (e <= s)
            {
                if (n[i][mid] < 0)
                {
                    ans = mid;
                    s = mid - 1;
                }
                else
                {
                    e = mid + 1;
                }
                mid = e + (s - e) / 2;
            }
            if (ans != -1)
            {
                count += n[i].size() - ans;
            }
        }
        return count;
    }
};