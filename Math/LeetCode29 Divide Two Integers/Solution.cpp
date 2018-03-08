class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int flag = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long a = labs(dividend);
        long long b = labs(divisor); 
        int res = 0;
        while (a >= b){
            long long tmp = b;
            int count = 1;
            while (a >= (tmp << 1)){
                tmp = tmp << 1;
                count = count << 1;
            }
            a -= tmp;
            res += count;
        }
        return (flag > 0 ? res : -res);
    }
};