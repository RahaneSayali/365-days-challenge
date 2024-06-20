
class Solution {
public:
    string reverseWords(string s) {
        
        string ans="";
        int i=0;
        int n=s.size();
       while(i<n){
            string temp="";
           while(s[i]==' '&& i<n)   //to avoid space
            i++;

            while(s[i]!=' ' && i<n) //store in temp char bt char
            {
            temp+=s[i];
            i++;
            }
            
        if(temp.size()>0)
        {
            if(ans.size()==0)
            ans=temp;
            else
            ans=temp+' '+ans;
        }
    }
        return ans; 
    }
};