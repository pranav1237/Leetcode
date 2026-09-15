#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long n = dividend;
        long long d = divisor;

        bool negative = (n < 0) ^ (d < 0);

        // Convert both safely to positive long long values
        n = n < 0 ? -n : n;
        d = d < 0 ? -d : d;

        long long ans = 0;

        while (n >= d) {
            long long temp = d;
            long long multiple = 1;

            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            n -= temp;
            ans += multiple;
        }

        if (negative)
            ans = -ans;

        if (ans > INT_MAX)
            return INT_MAX;

        if (ans < INT_MIN)
            return INT_MIN;

        return static_cast<int>(ans);
    }
};