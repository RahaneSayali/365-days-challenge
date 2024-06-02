class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        map<int, int> events;

        // Mark the start and end of each meeting
        for (const auto &meeting : meetings)
        {
            events[meeting[0]]++;     // Meeting starts
            events[meeting[1] + 1]--; // Meeting ends
        }

        int freeDays = 0;
        int ongoingMeetings = 0;
        int previousDay = 1; // Start from the first day

        // Process events in sorted order
        for (const auto &event : events)
        {
            int currentDay = event.first;

            // If there are no ongoing meetings, the days between previousDay and currentDay - 1 are free
            if (ongoingMeetings == 0)
            {
                freeDays += currentDay - previousDay;
            }

            // Update the number of ongoing meetings
            ongoingMeetings += event.second;

            // Move to the current day
            previousDay = currentDay;
        }

        // Account for the remaining days after the last event
        if (ongoingMeetings == 0 && previousDay <= days)
        {
            freeDays += days - previousDay + 1;
        }

        return freeDays;
    }
};