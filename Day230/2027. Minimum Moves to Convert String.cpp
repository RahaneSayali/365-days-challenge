class Solution {
public:
    int minimumMoves(string s) {
        int i = 0, n = s.length(), count = 0;
	while (i < n) {
		if (s[i] == 'O')  // If we find 'O' we simply move the pointer one step
			i++;
		else
			count++, i += 3;  // When we find 'X' we increment the count and move the pointer by 3 steps
	}
	return count;
    }
};