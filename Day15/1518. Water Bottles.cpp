class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int full = numBottles;
        int bottles = 0;
        do
        {
            full = full + (numBottles / numExchange);
            bottles = numBottles % numExchange;
            numBottles = numBottles / numExchange + bottles;
        } while (numBottles >= numExchange);
        return full;
    }
};