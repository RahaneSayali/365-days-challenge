class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        auto bounds_check = [n](int r, int c){ return r >= 0 && c >= 0 && r < n && c < n; };
        deque<tuple<int, int, int>> q;
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
            if (grid[i][j]) q.emplace_back(i, j, 1);
            --grid[i][j];
        }
        while (!q.empty()) {
            auto [i, j, safety] = q.front(); q.pop_front();
            array<pair<int, int>, 4> expand = {{{i+1, j}, {i-1, j}, {i, j+1}, {i, j-1}}};
            for (auto [r, c] : expand) if (bounds_check(r, c) && grid[r][c] == -1) {
                grid[r][c] = safety;
                q.emplace_back(r, c, safety+1);
            }
        }
        int min_safety = grid[0][0];
        q.emplace_back(0, 0, grid[0][0]);
        while (!q.empty()) {
            auto [i, j, safety] = q.front(); q.pop_front();
            min_safety = min(min_safety, safety);
            if (i == n-1 && j == n-1) break;
            array<pair<int, int>, 4> expand = {{{i+1, j}, {i-1, j}, {i, j+1}, {i, j-1}}};
            for (auto [r, c] : expand) if (bounds_check(r, c) && grid[r][c] != -1) {
                int safety = grid[r][c];
                grid[r][c] = -1;
                if (safety < min_safety) {
                    q.emplace_back(r, c, safety);
                } else {
                    q.emplace_front(r, c, safety);
                }
            }
        }
        return min_safety;
    }
};