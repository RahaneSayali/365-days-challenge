class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
    int n = s.size();
    string result(n, ' ');
    for (int i = 0; i < n; i++) {
        result[indices[i]] = s[i];
    }
    return result;
}
};