class Solution {
public:
    double myPow(double x, int n) {
    	// deal with base cases
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == 2) return x*x;
        if (n == -1) return 1 / x;
        // prepare for split
        int i = n / 2;
        int j = n - i;
        // if (+,last) or (-,first) digit of exponent is 0
        if (i == j) return myPow(myPow(x, i), 2);
        // if (+,last) digit of exponent is 1
        else if(i<j) return x*myPow(myPow(x, i), 2);
        // if (-,first) digit of exponent is 1
        else return 1/x*myPow(myPow(x, i), 2);
    }
};
