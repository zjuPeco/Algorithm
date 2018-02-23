#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
	void _print(vector<vector<int>>& matrix, int startX, int startY, int endX, int endY){
		if (endX < startX || endY < startY)
			return;
		int step[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
		int x = startX;
		int y = startY;
		cout << matrix[x][y] << " ";
		for (int i = 0; i < 4; i++){
			while (true){
				x += step[i][0];
				y += step[i][1];
				if (x == startX && y == startY)
					break;
				else if (x >= startX && x <= endX && y >= startY && y <= endY){
					cout << matrix[x][y] << " ";
				}
				else{
					break;
				}
			}
			x -= step[i][0];
			y -= step[i][1];
		}
		cout << endl;
		_print(matrix, startX + 1, startY + 1, endX - 1, endY - 1);
		return;
	}

public:
	void printMatrixClockwisely(vector<vector<int>>& matrix){
		int m = matrix.size();
		if (m <= 0)
			return;
		int n = matrix[0].size();
		_print(matrix, 0, 0, m - 1, n - 1);
	}
};

int main(){
	vector<vector<int>> matrix = {
		{ 1, 2, 3 },
		{ 5, 6, 7 },
	};
	Solution s;
	s.printMatrixClockwisely(matrix);
}