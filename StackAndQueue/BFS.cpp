// Link: https://www.geeksforgeeks.org/level-order-tree-traversal/

// Just written the function for the use of queue in BFS
vector<int> BFS(Node *root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    queue<Node*> q;
    q.push(root);
    while(q.isEmpty())
    {
        Node* temp=q.front();
        q.pop();
        ans.push_back(temp->data);
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return ans;
}