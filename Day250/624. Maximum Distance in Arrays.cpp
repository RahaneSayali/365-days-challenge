class Solution {
public:
    static int maxDistance(vector<vector<int>>& arrays) {
        int xMin=1e5, xMax=-1e5;
        int diff=0;
        int m=arrays.size();
        //1 pass 
        for(auto& arr: arrays){
            int a0=arr[0], aN=arr.back();
            diff=max({diff, aN-xMin, xMax-a0});
            xMin=min(a0, xMin);
            xMax=max(aN, xMax);
        }
        return diff;
    }
};