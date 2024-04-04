class Solution
{
public:
    vector<int> diffWaysToCompute(string str)
    {
        vector<int> output;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '+' || str[i] == '-' || str[i] == '*')
            {
                vector<int> left = diffWaysToCompute(str.substr(0, i));
                vector<int> right = diffWaysToCompute(str.substr(i + 1));

                for (auto x : left)
                {
                    for (auto y : right)
                    {
                        if (str[i] == '+')
                            output.push_back(x + y);
                        if (str[i] == '-')
                            output.push_back(x - y);
                        if (str[i] == '*')
                            output.push_back(x * y);
                    }
                }
            }
        }
        if (!output.size())
            output.push_back(stoi(str));
        return output;
    }
};