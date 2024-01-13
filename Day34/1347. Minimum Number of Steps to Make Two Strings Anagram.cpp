class Solution
{
public:
    int minSteps(string s, string t)
    {
        map<char, int> m;
        for (auto a : s)
            m[a]++; // calculating character from s
        for (auto a : t)
            m[a]--; // calculating character from t basically difference
        int ans = 0;
        for (auto a : m)
            ans += abs(a.second);
        return ans / 2;
    }
};