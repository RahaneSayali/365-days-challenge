class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> res(nums1.size(), -1); // result array

        stack<int> st;    // stack
        map<int, int> mp; // hash map

        for (int num : nums2)
        {

            // stack.top < num
            while (!st.empty() && st.top() < num)
            {
                mp[st.top()] = num;
                st.pop();
            }
            // push into stack
            st.push(num);
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            if (mp[nums1[i]])
                res[i] = mp[nums1[i]];
        }
        return res;
    }
};