class Solution {
public:
    void arrayMinMax(vector<int> &bloomDay,int &minElement,int &maxElement){
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<minElement){
                minElement=bloomDay[i];
            }
            if(bloomDay[i]>maxElement){
                maxElement=bloomDay[i];
            }
        }
    }
    bool isPossible(vector<int> &bloomDay,int days,int m,int k){
        int count=0,numOfBouq=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days){
                count++;
            }
            else{
                numOfBouq+=count/k;
                count=0;
            }
        }
        numOfBouq+=count/k;
        return numOfBouq>=m;
    }
    int minDays(vector<int> &bloomDay,int m,int k){
        // Edge case
        long long val=m*1ll*k*1ll;
        int n=bloomDay.size();
        if(val>n){
            return -1;
        }

        int low=INT_MAX,high=INT_MIN;
        arrayMinMax(bloomDay,low,high);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(bloomDay,mid,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};