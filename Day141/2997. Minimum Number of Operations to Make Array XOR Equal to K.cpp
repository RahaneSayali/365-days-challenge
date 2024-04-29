#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        bitset<20> xorSum=k;
        for(int x: nums)
            xorSum^=x;
        return xorSum.count();
    }
};