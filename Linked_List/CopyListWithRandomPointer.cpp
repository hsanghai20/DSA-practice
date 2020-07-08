// Link: https://leetcode.com/problems/copy-list-with-random-pointer/

//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

//Return a deep copy of the list.

//The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] 
//where:
    // val: an integer representing Node.val
    //random_index: the index of the node (range from 0 to n-1) where random pointer points to, 
    //or null if it does not point to any node.
 
 // solution: 
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
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> m;
        Node* ans=new Node(-1);
        Node* temp=ans;
        Node* temp1=ans;
        Node* again=head;
        int count=0;
        while(head!=NULL)
        {
            ans->next=new Node(head->val);
            m[head]=ans->next;
            ans=ans->next;
            head=head->next;
            count++;
        }
        while(again!=NULL)
        {
            if(again->random)
                temp1->next->random=m[again->random];
            temp1=temp1->next;
            again=again->next;
        }
        return temp->next;
    }
