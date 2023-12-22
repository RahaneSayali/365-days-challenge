class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> st;
        vector<int> v;

        for(int i=0;i<nums.size();i++)
        {
            if(st.count(nums[i]))
            {
                //if element if present
                v.push_back(nums[i]);
            }
            else
            {
                //if element is not present
                st.insert(nums[i]);
            }
        }
        return v;
    }
};