/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int sum = 0;
    void dfs(TreeNode *node)
    {
        if (node->left != nullptr)
        {
            if (node->left->left == nullptr && node->left->right == nullptr)
                sum += node->left->val;
            dfs(node->left);
        }
        if (node->right != nullptr)
        {
            dfs(node->right);
        }
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        sum = 0;
        dfs(root);
        return sum;
    }
};