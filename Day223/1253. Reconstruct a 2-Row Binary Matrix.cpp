class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower,
                                          vector<int>& colsum) {
        int n = colsum.size();

        int count1 = 0;
        int count2 = 0;

        for (int i = 0; i < n; i++) {
            if (colsum[i] == 1)
                count1++;

            if (colsum[i] == 2)
                count2 += 2;
        }

        if (((upper + lower) - (count1 + count2)) != 0)
            return {};

        int upp = upper-(count2/2);
        int low = lower-(count2/2);

        if (upp < 0 || low < 0)
            return {};

        vector<vector<int>> res(2, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            if (colsum[i] == 2) {
                res[0][i] = 1;
                res[1][i] = 1;
            }
            else if (colsum[i] == 1 && upp) {
                res[0][i] = 1;
                upp--;
            }
            else if (colsum[i] == 1 && low)
            {
                res[1][i] = 1;
                low--;
            }
        }

        return res;
    }
};