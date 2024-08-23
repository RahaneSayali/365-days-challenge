class Solution {
public:
    string fractionAddition(string s) {
        // Vectors to store the numerators and denominators separately
        std::vector<int> num;
        std::vector<int> den;

        int i = 0;
        int n = s.size();

        // If the string does not start with a negative sign, prepend a '+' sign
        if (s[0] != '-') {
            s = "+" + s;
        }

        // Parse the string to extract numerators and denominators
        while (i < n) {
            if (s[i] == '/') {
                // Finding the numerator
                int j = i - 1;
                int power = 0;
                int res = 0;

                // Traverse back to find the numerator before the '/' character
                while ('0' <= s[j] && s[j] <= '9') {
                    int num = s[j] - '0';
                    res = num * std::pow(10, power) + res;
                    j--;
                    power++;
                }

                // If the numerator is negative, multiply by -1
                if (s[j] == '-') {
                    res = res * (-1);
                }
                num.push_back(res);

                // Finding the denominator
                j = i + 1;
                bool isneg = false;

                // Check if the denominator is negative (which should not occur in a valid fraction)
                if (s[j] == '-') {
                    isneg = true;
                }
                res = 0;

                // Traverse forward to find the denominator after the '/' character
                while ('0' <= s[j] && s[j] <= '9') {
                    int num = s[j] - '0';
                    res = res * 10 + num;
                    j++;
                }

                // If the denominator was found to be negative, multiply by -1
                if (isneg) {
                    res = res * -1;
                }
                den.push_back(res);
            }
            i++;
        }

        // Calculate the least common multiple (LCM) of all denominators
        int lcm = 1;
        for (auto itr : den) {
            lcm = itr * lcm;
        }

        // Calculate the resulting numerator by summing up all numerators after adjusting them to the common denominator
        int numRes = 0;
        for (int i = 0; i < num.size(); i++) {
            numRes = numRes + (lcm / den[i]) * (num[i]);
        }

        // Find the greatest common divisor (GCD) of the resulting numerator and the LCM (which is now the denominator)
        int gcdVal = gcd(abs(numRes), lcm);
        
        // Simplify the fraction by dividing both the numerator and denominator by their GCD
        numRes /= gcdVal;
        lcm /= gcdVal;

        // Return the resulting fraction as a string in the form "numerator/denominator"
        return std::to_string(numRes) + "/" + std::to_string(lcm);
    }

private:
    // Function to calculate the greatest common divisor (GCD) using the Euclidean algorithm
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};