class Solution {
private:
    int min3(int a, int b, int c){
        return min(a, min(b, c));
    }
    
public:
    int nthUglyNumber(int n) {
        if (1 == n)
            return 1;
        vector<int> res;
        res.push_back(1);
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        int count = 1;
        while (count < n){
            int val = min3(res[p2]*2, res[p3]*3, res[p5]*5);
            res.push_back(val);
            while (res[p2] * 2 <= val)
                p2++;
            while (res[p3] * 3 <= val)
                p3++;
            while (res[p5] * 5 <= val)
                p5++;
            count++;
        }
        return res[n - 1];
    }
};