class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        map<int,int>m;
        int n=nums.size();
        int a=0;

        for(auto i:nums)
        a=max(a,i);
        int i=0,j=0;
        long long ans=0;
        while(j<n){
            m[nums[j]]++;
            while(m[a]>=k){
                ans=ans+n-j;
                m[nums[i]]--;
                i++;

            }
            j++;
        }
return ans;
    }
};