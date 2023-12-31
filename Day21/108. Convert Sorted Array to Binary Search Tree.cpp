class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
       TreeNode* build(vector<int>& nums,int left, int right) {
            if(left>right)
            return NULL;
        int mid = (left+right)/2;
        TreeNode* NewNode = new TreeNode(nums[mid]);
        NewNode->left = build(nums,left,mid-1);
        NewNode->right = build(nums,mid+1,right);
        return NewNode;
    }
};