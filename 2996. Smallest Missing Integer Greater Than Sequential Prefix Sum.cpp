class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        int n=nums.size();

        unordered_set<int>s;
        for(auto el:nums)s.insert(el);

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1)
            sum+=nums[i];
            else
            break;
        }
        while(s.find(sum)!=s.end()){
            sum++;
        }
        return sum;
    }
};