class Solution {
public:
    int mySqrt(int num) {
         int high= num,low=0;
        while(high>low){
            long int mid = low + ((long int)high - low + 1) / 2;
            if(mid<=sqrt(num))
                low = mid;
            else
                high = mid -1;
        }
        return low;
    }
};