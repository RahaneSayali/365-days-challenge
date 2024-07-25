class Solution {
public:
    int characterReplacement(string s, int k) {
        int r=0,l=0,maxfreq=0,maxlen=0;
        int hash[26]={0};
        int n=s.size();
        while(r<n){
            hash[s[r]-'A']++;

            maxfreq=max(maxfreq, hash[s[r]-'A']);

// Check if the current window size minus the maximum frequency character is greater than k
            if((r-l+1)-maxfreq > k){

                hash[s[l]-'A']--;
                l++;

            }
            if((r-l+1)-maxfreq <=k){

                maxlen=max(maxlen,r-l+1);
               
                 r++;
            }
            
        }
        return maxlen;
    }
};