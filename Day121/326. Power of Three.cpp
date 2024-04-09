class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
         return false;
        int l=0;
        int h=31;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(pow(3,mid)==n)
             return true;
            else if(pow(3,mid)<n)
              l=mid+1;
            else
             h=mid-1;
        }
        return false;
    }
};