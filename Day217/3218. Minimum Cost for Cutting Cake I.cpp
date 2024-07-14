class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<pair<int, char>> cuts;
    for (int cost : horizontalCut) {
        cuts.push_back({cost, 'h'});
    }
    for (int cost : verticalCut) {
        cuts.push_back({cost, 'v'});
    }

    // Sort cuts in descending order based on cost
    sort(cuts.rbegin(), cuts.rend());

    int h_pieces = 1; // Initial horizontal pieces
    int v_pieces = 1; // Initial vertical pieces
    int total_cost = 0;

    for (auto cut : cuts) {
        int cost = cut.first;
        char type = cut.second;

        if (type == 'h') {
            // Horizontal cut affects all vertical pieces
            total_cost += cost * v_pieces;
            h_pieces++;
        } else {
            // Vertical cut affects all horizontal pieces
            total_cost += cost * h_pieces;
            v_pieces++;
        }
    }  return total_cost;

    }
};