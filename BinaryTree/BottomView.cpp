// Link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// solution:
#include<bits/stdc++.h> 
using namespace std; 
  
// Tree node class 
struct Node 
{ 
    int data; //data of the node 
    int hd; //horizontal distance of the node 
    Node *left, *right; //left and right references 
  
    // Constructor of tree node 
    Node(int key) 
    { 
        data = key; 
        hd = INT_MAX; 
        left = right = NULL; 
    } 
}; 

void bottomView(Node* root)
{
  if(!root)
    return;
  queue<Node*> q;
  q.push(root);
  root->hd=0;
  Node* temp;
  map<int,int> m;
  while(!q.empty())
  {
    temp=q.front();
    q.pop();
    m[temp->hd]=temp->data;
    if(temp->left)
    {
      temp->left->hd=temp->hd-1;
      q.push(temp->left);
    }
    if(temp->right)
    {
      temp->right->hd=temp->hd+1;
      q.push(temp->right);
    }
  }
  for(auto i:m)
    cout << i.second << " ";
  cout << endl;
}  
// Driver Code 
int main() 
{ 
    Node *root = new Node(20); 
    root->left = new Node(8); 
    root->right = new Node(22); 
    root->left->left = new Node(5); 
    root->left->right = new Node(3);  
    root->right->right = new Node(25); 
    root->left->right->left = new Node(10); 
    root->left->right->right = new Node(14); 
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root); 
    return 0; 
} 