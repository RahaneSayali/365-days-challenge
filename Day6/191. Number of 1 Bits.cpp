// in this ques we are checking last bit 
// if its 1 then we will shift right  (to checking 1 we used (n&1 means 11=1))
// --

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n!=0){
            // checking last bit
            
            if(n&1){   /*n&1 means 11=1*/
                count++;  /*badha diya*/
            }
            n=n>>1;   /*right shift kr rhe*/
        }
        return count;
    }
};