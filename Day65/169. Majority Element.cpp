class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate=0;

        for(int num:nums){   //iterate in data structurs num 
            if(count==0){
                candidate=num;
            }
            if(num==candidate)
            count+=1;
            else count -=1;
        }
        return candidate;
    }
};


/* PSUDOCODE
  if(cnt=0){
    el=a[i];
  }
  if(a[i]==el)
  cnt +=1;
  else cnt-=1;
*/