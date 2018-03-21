#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
private:
    vector<vector<int>> dx;
    vector<vector<int>> dy;
    
public:
    int maxMonster(vector<int>& x, vector<int>& y, int n){
        getDeltaX(x);
        getDeltaY(y);
        int res = -1;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                for (int p = 0; p < n; p++){
                    if (p == i || p == j || isSameLine(i, j, p))
                        continue;
                    int count = 0;
                    for (int k = 0; k < n; k++){
                        if (isSameLine(i, j, k) || isVertical(i, j, p, k))
                            count++;
                    }
                    res = max(count, res);
                }
            }
        }
        return (res == -1 ? n : res);
    }
private:
    void getDeltaX(vector<int>& x){
        int n = x.size();
        dx = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                dx[i][j] = x[i] - x[j];
            }
        }
    }
    
    void getDeltaY(vector<int>& y){
        int n = y.size();
        dy = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                dy[i][j] = y[i] - y[j];
            }
        }
    }
    
    bool isSameLine(int i, int j, int k){
        return dx[i][j] * dy[j][k] - dx[j][k] * dy[i][j] == 0;
    }
    
    bool isVertical(int i, int j, int k, int p){
        return dy[i][j] * dy[k][p] + dx[i][j] * dx[k][p] == 0;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> x;
    vector<int> y;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
    }
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        y.push_back(tmp);
    }
    
    Solution sol;
    cout << sol.maxMonster(x, y, n) << endl;
    return 0;
}