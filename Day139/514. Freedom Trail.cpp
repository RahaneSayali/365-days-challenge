class Solution {
    int ring_size;
    unordered_map<char,vector<int>> mp;
    int clockwise(int curr, int new_pos){
        if(new_pos >= curr){
            return new_pos-curr;
        }
        return ring_size - (curr - new_pos);
    }
    int anti_clockwise(int curr, int new_pos){
        if(curr >= new_pos){
            return curr - new_pos;
        }
        return ring_size - (new_pos - curr);
    }
    int solve(string &key, int idx, int pos, vector<vector<int>>& dp){
        if(idx == key.size()){
            return 0; //end of key
        }
        if(dp[idx][pos] != -1){
            return dp[idx][pos];
        }
        int steps = INT_MAX;
        int key_value = key[idx];
        
        //going to all indexes
        for(int i = 0; i < mp[key_value].size(); i++){
            int new_pos = mp[key_value][i];
            int taken = solve(key,idx+1,new_pos,dp);
            //clockwise
            steps = min(steps,1+clockwise(pos,new_pos)+taken);
            //anticlockwise
            steps = min(steps,1+anti_clockwise(pos,new_pos)+taken);
        }
        return dp[idx][pos] = steps;
    }
public:
    int findRotateSteps(string& ring, string& key) {
        ring_size = ring.size();
        for(int i = 0; i < ring_size; i++){
            mp[ring[i]].push_back(i); 
        }

        vector<vector<int>> dp(key.size(),vector<int>(ring.size(),-1));
        return solve(key,0,0,dp);
    }
};