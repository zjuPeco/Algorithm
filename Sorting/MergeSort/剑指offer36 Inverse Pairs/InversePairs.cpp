#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
	int res;

private:
	void _merge(vector<int>& vec, int l1, int r1, int l2, int r2){
		vector<int> vec1, vec2;
		for (int i = l1; i <= r1; i++){
			vec1.push_back(vec[i]);
		}
		for (int i = l2; i <= r2; i++){
			vec2.push_back(vec[i]);
		}
		int m = r1;
		int n = r2;
		for (int i = r2; i >= l1; i--){
			if (m < l1){
				vec[i] = vec2[n - l2];
				n--;
				continue;
			}

			if (n < l2){
				vec[i] = vec1[m - l1];
				m--;
				continue;
			}

			if (vec1[m - l1] > vec2[n - l2]){
				res += (n - l2 + 1);
				vec[i] = vec1[m - l1];
				m--;
			}
			else{
				vec[i] = vec2[n - l2];
				n--;
			}
		}
	}

	void merge(vector<int>& vec, int l, int r){
		if (l >= r)
			return;

		int mid = l + (r - l) / 2;
		merge(vec, l, mid);
		merge(vec, mid + 1, r);
		_merge(vec, l, mid, mid + 1, r);
	}

public:
	int NumberOfInversePairs(vector<int>& vec){
		res = 0;
		merge(vec, 0, vec.size() - 1);
		return res;
	}
};

int main(){
	vector<int> vec = { 7, 5, 6, 4 };
	Solution s;
	int res = s.NumberOfInversePairs(vec);
	cout << res << endl;
}