class Solution {
public:
    int beautySum(string s) {
        int ans=0,n=s.size();
        for(int i=0;i<n;i++){
            
            map<char,int>m;
            for(int j=i;j<n;j++){
                m[s[j]]++;
                int m_f=0,l_f=INT_MAX;
                for(auto a:m){
                    m_f=max(m_f,a.second);
                    l_f=min(l_f,a.second);
                }
                ans+=(m_f-l_f);
            }

        }
        return ans;
    }
};