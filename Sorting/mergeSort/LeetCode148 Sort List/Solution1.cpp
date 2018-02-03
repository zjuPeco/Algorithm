class Solution {
private:
	void merge(ListNode* head, int left, int mid, int right){
		vector<int> vecLeft;
		vector<int> vecRight;
		ListNode* cur = head;
		for (int i = left; i <= mid; i++){
			vecLeft.push_back(cur->val);
			cur = cur->next;
		}
		for (int i = mid + 1; i <= right; i++){
			vecRight.push_back(cur->val);
			cur = cur->next;
		}
		cur = head;
		int m = left;
		int n = mid + 1;
		for (int k = left; k <= right; k++){
			if (m > mid){
				cur->val = vecRight[n - mid - 1];
				n++;
				cur = cur->next;
			}
			else if (n > right){
				cur->val = vecLeft[m - left];
				m++;
				cur = cur->next;
			}
			else if (vecLeft[m - left] < vecRight[n - mid - 1]){
				cur->val = vecLeft[m - left];
				m++;
				cur = cur->next;
			}
			else{
				cur->val = vecRight[n - mid - 1];
				n++;
				cur = cur->next;
			}
		}
	}

public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next)
			return head;
		int length = 0;
		ListNode* cur = head;
		while (cur){
			length++;
			cur = cur->next;
		}

		for (int sz = 1; sz <= length; sz += sz){
			cur = head;
			for (int i = 0; i < length - sz; i += 2 * sz){
				int tail = min(i + sz * 2 - 1, length - 1);
				merge(cur, i, i + sz - 1, tail);
				int count = tail - i + 1;
				while (count != 0){
					cur = cur->next;
					count--;
				}
			}
		}
		return head;
	}
};