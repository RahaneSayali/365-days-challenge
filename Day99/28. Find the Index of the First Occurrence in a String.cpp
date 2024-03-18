class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length()<needle.length()){
            return -1;
        }
        int index=-1;
        int result=-1;
        for(int i=0; i<haystack.length(); i++){
            if(haystack[i]==needle[0]){
                for(int j=0; j<needle.length(); j++){
                    if(haystack[i+j]==needle[j]){
                        index=-1;
                        continue;
                    }
                    else{
                        index=0;
                        break;
                    }
                }
                if(index==0){
                    result=-1;
                }
                else{
                    result=i;
                    break;
                }
            }
        }
        return result;
    }
};