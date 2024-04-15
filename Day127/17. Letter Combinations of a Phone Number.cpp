
class Solution
{
private:
    void solve(string digit, string output, int index, vector<string> &ans, string mapping[])
    {
        // base case
        if (index >= digit.length())
        {
            ans.push_back(output);
            return;
        }
        int number = digit[index] - '0'; // to convert string no. into number '2' to 2 we have to minus 0
        string value = mapping[number];  //aur uski string value nikalo from mapping table 


        //recursive call according to current character of input string 
        for (int i = 0; i < value.length(); i++)
        {
            output.push_back(value[i]);
            solve(digit, output, index + 1, ans, mapping);
            output.pop_back();//pop to again make output empty for next loop
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.length() == 0)
            return ans;

        string output = "";
        int index = 0;

        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};