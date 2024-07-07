class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles;
        int emptyBottles = numBottles;
        int fullBottles = 0;

        while (numExchange <= emptyBottles)
        {
            while (emptyBottles >=  numExchange)
            {
                fullBottles++;
                emptyBottles -= numExchange;
                numExchange++;
            }

            res += fullBottles;
            emptyBottles += fullBottles;
            fullBottles = 0;
        }

        return res;

    }
};