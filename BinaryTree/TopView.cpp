// Link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// solution:
#include <bits/stdc++.h> 
using namespace std; 
  
// Structure of binary tree 
struct Node 
{ 
    Node * left; 
    Node* right; 
    int hd; 
    int data; 

    Node(int key)
    {
      data=key;
      left=right=NULL;
      hd=INT_MAX;
    }
}; 

void topview(Node* root)
{
  map<int,int> m;
  queue <Node* > q;
  q.push(root);
  root->hd=0;
  m[0]=root->data;
  Node* temp=root;
  while(!q.empty())
  {
    temp=q.front();
    q.pop();
    if(temp->left)
    {
      if(m.find(temp->hd-1)==m.end())
      {
        m[temp->hd-1]=temp->left->data;
      }
      temp->left->hd=temp->hd-1;
      q.push(temp->left);
    }
    if(temp->right)
    {
      if(m.find(temp->hd+1)==m.end())
      {
        m[temp->hd+1]=temp->right->data;
      }
      temp->right->hd=temp->hd+1;
      q.push(temp->right);
    }
  }
  for(auto i:m)
    cout << i.second << " ";
  cout << endl;
}

// Driver Program to test above functions 
int main() 
{ 
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6);
    root->right->right= new Node(7); 
    cout<<"Following are nodes in top view of Binary Tree\n";  
    topview(root); 
    return 0; 
} 