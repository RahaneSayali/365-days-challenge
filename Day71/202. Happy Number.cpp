class Solution {
public:
    int sumOfSquares(int n) {
        int sum = 0;
        while(n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = sumOfSquares(n);
        if(slow == 1 || fast == 1) return true;
        while(slow != fast) {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
            if(slow == 1 || fast == 1) return true;
        }
        return false;
    }
};