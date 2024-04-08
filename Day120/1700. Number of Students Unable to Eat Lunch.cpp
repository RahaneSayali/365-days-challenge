class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zerocount=0,onecount=0;

        for(int student:students){
            if(student==0)
            zerocount++;
            else
            onecount++;
        }
        for(int sandwich:sandwiches){
            if(sandwich==0 && zerocount==0)return onecount;
            if(sandwich==1 && onecount==0)return zerocount;

            if(sandwich==0)zerocount--;
            else onecount--;
        }
        return 0;
    }
};