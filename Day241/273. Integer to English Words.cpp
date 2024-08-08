string eng[] = {"",        "One",     "Two",       "Three",    "Four",
                "Five",    "Six",     "Seven",     "Eight",    "Nine",
                "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
                "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
                "Twenty",  "Thirty",  "Forty",     "Fifty",    "Sixty",
                "Seventy", "Eighty",  "Ninety",    "Hundred",  "Thousand",
                "Million", "Billion"};
int digit[] = {0,  1,  2,  3,  4,  5,  6,   7,    8,       9,         10,
               11, 12, 13, 14, 15, 16, 17,  18,   19,      20,        30,
               40, 50, 60, 70, 80, 90, 100, 1000, 1000000, 1000000000};

class Solution {
public:
     static string numberToWords(int num, int cnt=0) {
         if (num == 0) return (cnt==0)?"Zero":"";
        if (num<=20) return eng[num];
        int i=upper_bound(digit, end(digit), num)-digit-1;
        auto [q, r]=div(num, digit[i]);
        string ans="";
        if (digit[i]>=100)
            ans+= numberToWords(q, cnt+1)+" "+eng[i];
        else ans=eng[i];
        if (r>0) ans+=" " + numberToWords(r, cnt+1);
        
        return ans;
    }
};