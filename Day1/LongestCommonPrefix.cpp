class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        sort(strs.begin(), strs.end());

        int a = strs.size();

        string n = strs[0], m = strs[a - 1], ans = "";

        for (int i = 0; i < n.size(); i++)
        {
            if (n[i] == m[i])
            {
                ans += n[i];
            }
            else
                break;
        }
        return ans;
    }
};