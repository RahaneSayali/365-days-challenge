class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count = 0;
        for(auto i : nums){
            if(i == 0) return 0;

            else if(i < 0) count++;
        }
        if(count & 1) return -1;  //count & 1 checks whether the result is odd(-1) also we cn use if(count % 2 ==1)=>odd
        else
        return 1;
    }
};