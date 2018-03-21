#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int x): val(x), prev(NULL), next(NULL){}
};

class Solution{
public:
    void getList(int n){
        ListNode* head = NULL;
        ListNode* tail = NULL;
        for (int i = 0; i < n; i++){
            int val;
            cin >> val;
            if (!head){
                head = new ListNode(val);
                tail = head;
                continue;
            }
            if (i % 2 == 0){
                head->prev = new ListNode(val);
                head->prev->next = head;
                head = head->prev;
            }
            else{
                tail->next = new ListNode(val);
                tail->next->prev = tail;
                tail = tail->next;
            }
        }
        if (n % 2 == 1){
            while (head){
                cout << head->val << (head->next ? " " : "");
                head = head->next;
            }
        }
        else{
            while (tail){
                cout << tail->val << (tail->prev ? " " : "");
                tail = tail->prev;
            }
        }
        return;
    }
};

int main(){
    int n;
    cin >> n;
    Solution sol;
    sol.getList(n);
}