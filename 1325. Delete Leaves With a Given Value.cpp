class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) {
            // If the current node is nullptr, return nullptr
            return nullptr;
        }

        // Recursively process the left subtree
        root->left = removeLeafNodes(root->left, target);
        // Recursively process the right subtree
        root->right = removeLeafNodes(root->right, target);

        // Check if the current node is a leaf node with the target value
        if (!root->left && !root->right && root->val == target) {
            // If true, return nullptr to remove this node
            return nullptr;
        }

        // If the current node is not a target leaf node, return the current
        // node
        return root;
    }
};