class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> order1 = generateTopologicalSort(rowConditions, k);
        vector<int> order2 = generateTopologicalSort(colConditions, k);
        
        if (order1.size() < k || order2.size() < k) {
            return {};
        }
        
        unordered_map<int, int> m;
        for (int i = 0; i < k; i++) {
            m[order2[i]] = i;
        }
        
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            ans[i][m[order1[i]]] = order1[i];
        }
        
        return ans;
    }

private:
    vector<int> generateTopologicalSort(const vector<vector<int>>& A, int k) {
        vector<int> deg(k, 0);
        vector<int> order;
        vector<vector<int>> graph(k);
        queue<int> q;
        
        for (const auto& c : A) {
            graph[c[0] - 1].push_back(c[1] - 1);
            deg[c[1] - 1]++;
        }
        
        for (int i = 0; i < k; i++) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            order.push_back(x + 1);
            for (int y : graph[x]) {
                if (--deg[y] == 0) {
                    q.push(y);
                }
            }
        }
        
        return order;
    }
};