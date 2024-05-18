class Solution {
public:
        int ans;
    int distributeCoins(TreeNode* root) {
         ans = 0;
        countSteps(root);
        return ans;
    }
    
    int countSteps(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftCoins = countSteps(root->left);
        int rightCoins = countSteps(root->right);
      ans += abs(leftCoins) + abs(rightCoins);
        return (root->val - 1) + leftCoins + rightCoins;
    }
};