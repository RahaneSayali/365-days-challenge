class Solution
{
public:
    // an alias "int2" for the pair of integers
    using int2 = pair<int, int>;

    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        // adjacency list to represent the connections between people and their meeting times
        vector<vector<int2>> adj(n);

        // Build the adjacency lists based on the provided meetings
        for (auto &meet : meetings)
        {
            int x = meet[0], y = meet[1], time = meet[2];
            adj[x].emplace_back(time, y); // (time, person y)
            adj[y].emplace_back(time, x);
        }

        // a vector to keep track of the known meeting times of each person
        vector<int> known(n, INT_MAX);

        // vector to store the final list of people
        vector<int> list;

        // a priority queue for the meeting times and corresponding people (min heap)
        priority_queue<int2, vector<int2>, greater<int2>> pq;

        // Add the initial meetings of 0 & first person to the priority queue
        pq.emplace(0, 0);
        pq.emplace(0, firstPerson);

        // Process the meetings using a while loop until the priority queue is empty
        while (!pq.empty())
        {
            // Extract the meeting time and corresponding person with the earliest meeting time
            auto [s, x] = pq.top();
            pq.pop();

            // If the person is already known, skip to the next iteration
            if (known[x] != INT_MAX)
                continue;

            // Add the person to the final list
            list.push_back(x);

            // Update the known meeting time for the person
            known[x] = s;

            // Iterate through the adjacent list of the current person
            for (auto &[t, y] : adj[x])
            {
                // Check if the adjacent person is already known or the meeting time is earlier
                if (known[y] != INT_MAX || t < s)
                    continue;

                // Add the meeting time and corresponding person to the priority queue
                pq.emplace(t, y);
            }
        }

        // Return the final list of people who have attended meetings
        return list;
    }
};