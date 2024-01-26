#pragma GCC optimize("O3", "unroll-loops")
using int2 = pair<int, int>;
vector<int2> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int mod = 1e9 + 7;
class Solution
{
public:
    int findPaths(int m, int n, int maxMove, int Row, int Column)
    {
        int dp[2][51][51];
        memset(dp, 0, sizeof(dp));
        for (int k = 1; k <= maxMove; k++)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    long long ans = 0;
                    for (auto [a, b] : moves)
                    {
                        int r = i + a, c = j + b;
                        if (r < 0 || r >= m || c < 0 || c >= n)
                            ans++;
                        else
                            ans += dp[(k - 1) & 1][r][c];
                    }
                    dp[k & 1][i][j] = ans % mod;
                }
            }
        }
        return dp[maxMove & 1][Row][Column];
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();