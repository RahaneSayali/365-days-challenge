class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int n = asteroids.size();
        for(int i = 0; i < n; i++) {
            int curr = asteroids[i];
            while(!st.empty() && curr < 0 && st.back() > 0) {
                int sum = curr + st.back();

                if (sum < 0) {
                    st.pop_back();
                } else if (sum > 0) {
                    curr = 0;
                } else {
                    st.pop_back();
                    curr = 0;
                }
            }
            if (curr != 0) {
                st.push_back(curr);
            }
        }
        return st;
    }
};
