class Solution
{
public:
    string makeGood(string s)
    {
        stack<char> stack;

        for (char c : s)
        {
            if (!stack.empty() && std::abs(c - stack.top()) == 32)
            {
                stack.pop();
            }
            else
            {
                stack.push(c);
            }
        }

        string result;
        while (!stack.empty())
        {
            result = stack.top() + result;
            stack.pop();
        }

        return result;
    }
};