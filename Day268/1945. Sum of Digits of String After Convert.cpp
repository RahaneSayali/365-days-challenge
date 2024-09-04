class Solution {
public:
    int getLucky(string s, int k) {
        // Convert each character in the string to its corresponding numeric value
        string number = "";
        for (char x : s) {
            number += to_string(x - 'a' + 1);
        }
        
        // Perform the transformation `k` times
        while (k > 0) {
            int temp = 0;
            for (char x : number) {
                temp += x - '0';  // Sum the digits of the current number
            }
            number = to_string(temp);  // Convert the sum back to a string
            k--;
        }
        return stoi(number);  // Return the final result as an integer
    }
};