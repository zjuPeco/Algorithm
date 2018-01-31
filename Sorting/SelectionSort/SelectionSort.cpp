#include <iostream>
#include <string>

using namespace std;

template<typename T>
int length(T& data){
	return sizeof(data) / sizeof(data[0]);
}

template<typename T>
void selectionSort(T& arr){
	for (int i = 0; i < length(arr); i++){
		int min_idx = i;
		for (int j = i + 1; j < length(arr); j++){
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		swap(arr[i], arr[min_idx]);
	}
}

template<typename T>
void printArr(T& arr){
	for (int i = 0; i < length(arr); i++){
		cout << arr[i] << (i == length(arr) - 1 ? "\n" : " ");
	}
}

struct Movies {
	string name;
	double score;

	bool operator<(const Movies& otherMoive){
		return score != otherMoive.score ?
			score > otherMoive.score : name < otherMoive.name;
	}

	friend ostream& operator<<(ostream &os, const Movies &movie){

		os << "(" << movie.name << ": " << movie.score << ")";
		return os;
	}
};

int main(){
	//整数排序测试
	int test1[] = { 1, 5, 3, 4, 9, 5, 3 };
	selectionSort(test1);
	printArr(test1);
	
	//字符串排序测试
	string test2[] = { "a", "n", "e", "m", "b" };
	selectionSort(test2);
	printArr(test2);

	//自定义类排序测试
	Movies test3[] = { { "Superman", 4.0 }, { "Inception", 5.0 }, 
	{ "Batman", 4.5 }, { "Spiderman", 4.0 } };
	selectionSort(test3);
	printArr(test3);
}