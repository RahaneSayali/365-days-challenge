class Solution {
public:
    int numTeams(vector<int>& rating) {
        int total = 0;

        for ( int i = 0 ; i < rating.size() ; i ++ ){
            int right_less = 0 , right_more = 0 , left_less = 0 , left_more = 0;

            for ( int j = i + 1 ; j < rating.size() ; j ++ ){
                if ( rating[j] < rating[i] ) right_less++;
                else if ( rating[i] < rating[j] ) right_more++;
            }
            for ( int j = 0 ; j < i ; j ++ ){
                if ( rating[j] < rating[i] ) left_less++;
                else if ( rating[i] < rating[j] ) left_more ++;
            }

            total += right_less*left_more + right_more*left_less;
        }

        return total;
    }
};