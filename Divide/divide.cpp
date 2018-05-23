class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool positive = !((dividend > 0) ^ (divisor > 0));
        long long int d1 = dividend;
        long long int d2 = divisor;
        d1 = abs(d1);
        d2 = abs(d2);
        if (d2 == 1 && positive) return d1;
        else if (d2 == 1 && !positive) return (0 - d1);
        double logQ = log(d1) - log(d2);
        int Q = pow(double(exp(1)), logQ);
        if (positive) return Q;
        else return (0 - Q);
    }
};
