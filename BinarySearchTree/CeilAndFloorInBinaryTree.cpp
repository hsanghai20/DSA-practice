#include <bits/stdc++.h> 
using namespace std; 
struct Node
{
  int key;
  Node* left;
  Node* right;
};
Node* newnode(int item)
{
  Node* temp=new Node;
  temp->key=item;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
Node* insert(Node* root,int val)
{
  if(root == NULL)
    return newnode(val);
  if(root->key>val)
    root->left=insert(root->left,val);
  else
  {
    root->right=insert(root->right,val);
  }
  return root;
}
void Ceil(Node* root,int k,int& ceil)
{
  if(root==NULL)
    return;
  if(root->key==k)
  {
    ceil = k;
    return;
  }
  else if(root->key>k)
  {
    ceil=root->key;
    Ceil(root->left,k,ceil);
  }
  else
  {
    Ceil(root->right,k,ceil);
  }
}
void Floor(Node* root,int k,int& floor)
{
  if(root==NULL)
    return;
  if(root->key==k)
  {
    floor=k;
    return;
  }
  else if(root->key>k)
  {
    Floor(root->left,k,floor);
  }
  else
  {
    floor=root->key;
    Floor(root->right,k,floor);
  }
}
int main() 
{ 
  int k;
  cin >> k;
  Node* root=NULL;
  root = insert(root, 50); 
  insert(root, 30); 
  insert(root, 20); 
  insert(root, 40); 
  insert(root, 70); 
  insert(root, 60); 
  insert(root, 80); 
  int ceil=-1;
  int floor=-1;
  Ceil(root,k,ceil);
  Floor(root,k,floor);
  cout << ceil << " " << floor << endl;
}