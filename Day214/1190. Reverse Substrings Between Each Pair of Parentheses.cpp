class Solution {
public:
    string reverseParentheses(string s) {
        deque<int> ind_stack;
        vector<char> res;

        for (char char_s : s) {
            if (char_s == '(') {
                ind_stack.push_back(res.size());
            } else if (char_s == ')') {
                int start_ind = ind_stack.back();
                ind_stack.pop_back();
                reverse(res.begin() + start_ind, res.end());
            } else {
                res.push_back(char_s);
            }
        }

        return string(res.begin(), res.end());
    }
};