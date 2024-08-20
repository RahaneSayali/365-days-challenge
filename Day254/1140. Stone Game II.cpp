class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int totalPiles = piles.size();
        vector<int> suffixSums(totalPiles + 1, 0);
        for (int i = totalPiles - 1; i >= 0; i--) {
            suffixSums[i] = suffixSums[i + 1] + piles[i];
        }
        
        vector<vector<int>> memo(totalPiles, vector<int>(totalPiles + 1, 0));
        
        function<int(int,int)> maxStonesAliceCanGet = [&](int m, int currentPile) -> int {
            if (currentPile >= totalPiles) return 0;
            
            if (currentPile + 2 * m >= totalPiles) {
                return suffixSums[currentPile];
            }
            
            if (memo[currentPile][m] != 0) return memo[currentPile][m];
            
            int maxStones = 0;
            
            for (int x = 1; x <= 2 * m; x++) {
                int currentStones = suffixSums[currentPile] - maxStonesAliceCanGet(max(m, x), currentPile + x);
                maxStones = max(maxStones, currentStones);
            }
            
            memo[currentPile][m] = maxStones;
            return maxStones;
        };
        
        return maxStonesAliceCanGet(1, 0);
    }
};