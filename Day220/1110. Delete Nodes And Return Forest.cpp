class Solution {
    vector<TreeNode*>res;
    unordered_set<int>st;
    void deleteNode(TreeNode* &root){
        if(root){
            deleteNode(root->left);
            deleteNode(root->right);
            if(st.find(root->val)!=st.end()){
                if(root->left) res.push_back(root->left);
                if(root->right) res.push_back(root->right);
                root=NULL;
                
            }
        }
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i=0;i<to_delete.size();i++){
            st.insert(to_delete[i]);
        }
        deleteNode(root);
        if(root)res.push_back(root);
        return res;
    }
};