/*Input: n = 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10
If you directly used n instead of creating a separate variable m in the bitwiseComplement function,
the loop that calculates the mask would modify the value of n.
n is used both to calculate the mask and to compute the bitwise complement. However, the loop modifies the
value of n, and by the time you reach the bitwise complement calculation (int ans = (~n) & mask;), the value of n has been altered.
*/

class Solution
{
public:
    int bitwiseComplement(int n)
    {
        int m = n;
        int mask = 0;
        // edge case
        if (n == 0)
        {
            return 1;
        }
        while (m != 0)
        {
            m = m >> 1;
            mask = (mask << 1) | 1;
        }
        int ans = (~n) & mask;
        return ans;
    }
};