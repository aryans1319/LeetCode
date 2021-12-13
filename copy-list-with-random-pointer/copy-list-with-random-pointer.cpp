/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *dummyNode = new Node(-1);
        Node *runner = dummyNode;
        
        Node *current = head;
        unordered_map<Node*,Node*>mp;
        
        while(current!=NULL){
            Node *newNode = new Node(current->val);
            runner->next = newNode;
            mp[current] = newNode;
            current = current->next;
            runner = runner->next; 
        }
        
        current = head;
        runner = dummyNode->next;
        
        while(current!=NULL){
            if(current->random!=NULL){
                runner->random = mp[current->random];
            }
            runner=runner->next;
            current=current->next;
        }
        return dummyNode->next;
    }
};