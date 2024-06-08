class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        deque<int> queue; // This will simulate our queue of players

    for (int i = 0; i < n; ++i) {
        queue.push_back(i);
    }

    int currentWinner = queue.front();
    queue.pop_front();
    int winCount = 0;

    while (winCount < k && winCount < n - 1) {
        int challenger = queue.front();
        queue.pop_front();

        if (skills[currentWinner] > skills[challenger]) {
            // Current winner wins again
            queue.push_back(challenger);
            winCount++;
        } else {
            // Challenger becomes the new winner
            queue.push_back(currentWinner);
            currentWinner = challenger;
            winCount = 1;
        }
    }

    return currentWinner;
    }
};