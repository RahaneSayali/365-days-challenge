class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        int n = 0;
        map<int, int> m;

        for (auto x : nums)
        {
            m[x]++;
            n = max(n, m[x]);
        }
        vector<vector<int>> ans(n);
        vector<set<int>> s(n);

        for (auto x : nums)
        {
            for (int i = 0; i < n; i++)
            {
                if (s[i].find(x) == s[i].end())
                {
                    ans[i].push_back(x);
                    s[i].insert(x);
                    break;
                }
            }
        }
        return ans;
    }
};