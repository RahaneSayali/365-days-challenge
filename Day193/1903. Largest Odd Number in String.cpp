//Time Complexity: O(n), where n is the length of the input string.
//Space Complexity: O(1) (excluding the input and output storage).
class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();
        for(int i=n-1;i>=0;i--){
            if((num[i]-'0') %2 !=0 ){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};