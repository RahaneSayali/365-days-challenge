#pragma GCC optimize("O3", "unroll-loops")
class Solution
{
public:
    int ans = 0;
    void dfs(TreeNode *node, unsigned parity)
    {
        if (!node)
            return;
        int x = node->val;
        parity ^= (1 << x);
        if (!node->left && !node->right)
        {
            if (__builtin_popcount(parity) <= 1)
                ans++;
            return;
        }
        dfs(node->left, parity);
        dfs(node->right, parity);
    }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        unsigned parity = 0;
        dfs(root, parity);
        return ans;
    }
};