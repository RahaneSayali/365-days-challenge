class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        std::unordered_map<int, int> freqCounter;
        for (int num : nums)
        {
            freqCounter[num]++;
        }

        int maxFrequency = 0;
        for (const auto &entry : freqCounter)
        {
            maxFrequency = std::max(maxFrequency, entry.second);
        }

        int maxFreqElements = 0;
        for (const auto &entry : freqCounter)
        {
            if (entry.second == maxFrequency)
            {
                maxFreqElements++;
            }
        }

        int totalFrequency = maxFrequency * maxFreqElements;

        return totalFrequency;
    }
};