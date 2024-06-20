//TC -> O(N)
class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        bool flag=true;
        string ans="";

        for(int i=0;i<s.size();i++){

            if(s[i]=='(')
                count++;

            else if(s[i]==')')
                count--;
            
            if((count==1 && s[i]=='(') || count==0)
        continue;
        else{
            ans +=s[i];
        }
    }
     return ans;
    }
};