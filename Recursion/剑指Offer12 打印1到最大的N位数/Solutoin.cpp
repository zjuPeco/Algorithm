#include <iostream>

using namespace std;

class Solution {
private:
	void _printNum(char* number, int length, int idx){
		if (idx >= length){
			for (int i = 0; i < length; i++){
				cout << number[i] << (i == length - 1 ? "\n" : "");
			}
			return;
		}

		for (int i = 0; i < 10; i++){
			number[idx] = i + '0';
			_printNum(number, length, idx + 1);
		}
	}

public:
	void printNum(int n){
		if (n <= 0)
			return;

		char* number = new char[n + 1];
		memset(number, '0', n);
		number[n] = '\0';

		for (int i = 0; i < 10; i++){
			number[0] = i + '0';
			_printNum(number, n, 1);
		}
		delete[] number;
	}
};

int main(){
	Solution s;
	s.printNum(3);
}