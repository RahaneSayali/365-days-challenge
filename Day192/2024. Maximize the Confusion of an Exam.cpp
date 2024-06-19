class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0;
        int j = 0;

        int countF = 0;
        int countT = 0;
        int ans = 0;
        while(j < answerKey.length()) {
            char ch = answerKey[j];
            if(ch == 'T') {
                countT++;
            } else {
                countF++;
            }

            while(min(countT, countF) > k) {
                ch = answerKey[i];
                if(ch == 'T') {
                    countT--;
                } else {
                    countF--;
                }
                i++;
            }
            ans = max(ans, (j-i+1));
            j++;
        }
        return ans;
    }
};