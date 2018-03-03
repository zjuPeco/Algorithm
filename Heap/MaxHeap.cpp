#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template<typename Item>
class MaxHeap{
private:
	vector<Item> heap;
	int count;

private:
	void _shiftdown(int i){
		if (i < 0 || i >= count)
			return;
		Item tmp = heap[i];
		while (i < count){
			int j = 2 * i + 1;
			if (j >= count){
				heap[i] = tmp;
				return;
			}
			if (j + 1 <= count - 1 && heap[j] < heap[j + 1])
				j += 1;
			if (tmp < heap[j]){
				heap[i] = heap[j];
				i = j;
			}
			else{
				heap[i] = tmp;
				return;
			}
		}
		return;
	}

	void _shiftup(int i){
		if (i < 0 || i >= count)
			return;
		Item tmp = heap[i];
		while (i > 0){
			int j = (i - 1) / 2;
			if (heap[j] < tmp){
				heap[i] = heap[j];
				i = j;
			}
			else{
				heap[i] = tmp;
				return;
			}
		}
		heap[i] = tmp;
		return;
	}

public:
	MaxHeap(vector<Item>& vec){
		// copy this vec to heap
		heap.insert(heap.end(), vec.begin(), vec.end());
		count = vec.size();
		for (int i = (vec.size() - 2) / 2; i >= 0; i--){
			_shiftdown(i);
		}
		
	}

	void addItem(Item item){
		if (count < heap.size())
			heap[count] = item;
		else
			heap.push_back(item);
		count++;
		_shiftup(count - 1);
	}

	bool isEmpty(){
		return count == 0;
	}

	Item extractMax(){
		assert(!isEmpty());
		Item val = heap[0];
		swap(heap[0], heap[count - 1]);
		count--;
		_shiftdown(0);
		return val;
	}

	Item getMax(){
		assert(!isEmpty());
		return heap[0];
	}
};


int main(){
	vector<int> vec = { 2, 3, 5, 4, 8, 6, 7, 4, 11, 15, 18, 10 };
	MaxHeap<int> h(vec);
	h.addItem(20);
	h.addItem(6);
	while (!h.isEmpty()){
		cout << h.extractMax() << endl;
	}
}