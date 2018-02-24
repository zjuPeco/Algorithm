/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> mp;
        RandomListNode* node = head;
        while (node){
            mp[node] = new RandomListNode(node->label);
            node = node->next;
        }
        
        node = head;
        
        while (node){
            if (node->next)
                mp[node]->next = mp[node->next];
            if (node->random)
                mp[node]->random = mp[node->random];
            node = node->next;
        }
        return mp[head];
    }
};