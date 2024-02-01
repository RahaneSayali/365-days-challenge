class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=1;i<n;i++){  //i=1 because if i=0 then nums[0-1]=nums[-1]
            if(nums[i-1]>nums[i]){
                count++;
            }
        }
     if(nums[n-1]>nums[0])
     count ++;
     return count<=1;  //case 4  for all elements are equal 
    }
};