class Solution {
private:
    int count = 0;
    const int MAX_DISTANCE = 10;

    vector<int> dfs(TreeNode* node, int distance) {
        if (!node) return vector<int>(MAX_DISTANCE + 1, 0);
        
        if (!node->left && !node->right) {
            vector<int> res(MAX_DISTANCE + 1, 0);
            res[1] = 1;
            return res;
        }
        
        vector<int> left = dfs(node->left, distance);
        vector<int> right = dfs(node->right, distance);
        
        for (int i = 1; i <= distance; i++) {
            for (int j = 1; j <= distance - i; j++) {
                count += left[i] * right[j];
            }
        }
        
        vector<int> res(MAX_DISTANCE + 1, 0);
        for (int i = 1; i < MAX_DISTANCE; i++) {
            res[i + 1] = left[i] + right[i];
        }
        
        return res;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return count;
    }
};