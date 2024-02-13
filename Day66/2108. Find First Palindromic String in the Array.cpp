class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            if (isPalindrome(words[i]))
                return words[i];
        }
        return "";
    }

public:
    bool isPalindrome(string s)
    {
        int start = 0;
        int end = s.size() - 1;
        while (start < end)
        {
            if (s[start] == s[end])
            {
                start++;
                end--;
            }
            else
                return false;
        }
        return true;
    }
};

/*
another solution

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
          string temp=words[i];
          reverse(temp.begin(),temp.end());
          if(temp==words[i]) return words[i];
        }
        return "";
    }
};*/