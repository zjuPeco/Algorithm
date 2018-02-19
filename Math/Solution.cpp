class Solution {
private:
    double posPow(double x, int n){
        if (1 == n)
            return x;
        if (0 == n)
            return 1;
        double res = myPow(x, n >> 1);
        res *= res;
        if (n & 0x1 == 1){
            res *= x;
        }
        return res;
    }
    
public:
    double myPow(double x, int n) {
        if (-2147483648 == n){
            double res = posPow(x, 2147483647);
            res *= x;
            return 1.0 / res;
        }
        else if (n < 0){
            double res = posPow(x, -n);
            return 1.0 / res;
        }
        else{
            return posPow(x, n);
        }
    }
};