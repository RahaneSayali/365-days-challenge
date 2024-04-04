class Solution {
public:
    int maxDepth(string s) {
        int ans=0,opening=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                opening++;
            }
            else if(s[i]==')'){
                opening--;
            }
            ans=max(ans,opening);
        }
        return ans;
    }
};