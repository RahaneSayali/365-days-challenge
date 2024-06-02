class Solution
{
public:
    int minimumChairs(string s)
    {
        int maxchairs = 0;
        int current = 0;
        for (char event : s)
        {
            if (event == 'E')
            {
                current++;
            }
            else if (event == 'L')
            {
                current--;
            }
            maxchairs = max(maxchairs, current);
        }
        return maxchairs;
    }
};