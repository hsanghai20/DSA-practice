// Link: https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

// solution:
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
void findinorder(Node* root,Node*& pre,Node*& suc,int k)
{
  if(root==NULL)
    return;
  if(root->key==k)
  {
    if(root->left!=NULL)
    {
      Node* temp=root->left;
      while(temp!=NULL)
      {
        pre=temp;
        temp=temp->right;
      }
    }
    if(root->right!=NULL)
    {
      Node* temp=root->right;
      while(temp!=NULL)
      {
        suc=temp;
        temp=temp->left;
      }
    }
    return;
  }
  if(root->key>k)
  {
    suc=root; // if want to print -1 if key not found dont write this line
    findinorder(root->left,pre,suc,k);
  }
  else
  {
    pre=root;// if want to print -1 if key not found dont write this line
    findinorder(root->right,pre,suc,k); 
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
  Node* pre=NULL;
  Node* suc=NULL;
  findinorder(root,pre,suc,k);
  cout << pre->key << " " << suc->key << endl;
}