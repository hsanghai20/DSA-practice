// Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// solution:
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
    void connect(Node* temp,Node* temp1)
    {
        if(!temp || !temp1)
            return;
        temp->next=temp1;
        connect(temp->left,temp->right);
        connect(temp->right,temp1->left);
        connect(temp1->left,temp1->right);
    }
    Node* connect(Node* root) {
         if(!root)
             return root;
        root->next=NULL;
        connect(root->left,root->right);
        return root;
    }