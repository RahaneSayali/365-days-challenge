class Solution {
public:
    static int minSteps(int n) {
        if (n==1) return 0;// edge case
        int sum=0, sqrtn=sqrt(n), n0=n;
        bool isPrime=1;
        for(int p=2; p<=sqrtn; p++){
            int exp=0;
            while (n0%p==0){// small prime p before p^k
                exp++; 
                n0/=p;
            }
            if (exp) isPrime=0;
            sum+=exp*p;
        }
        if (n0>1) sum+=n0;// n0 must be a prime
        return (isPrime)?n:sum;
    }
};