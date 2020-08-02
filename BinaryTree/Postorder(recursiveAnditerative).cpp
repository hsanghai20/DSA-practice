// LinK:https://leetcode.com/problems/binary-tree-postorder-traversal/

// solution: (recursive)
void postorder(TreeNode* root,vector<int>& ans)
    {
        if(!root)
            return;
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }

// solution:(iterative)
 vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        stack<TreeNode*> s;
        s.push(root);
        set<TreeNode*> visited;
        while(!s.empty())
        {
            TreeNode* temp=s.top();
            if(temp->left!=NULL && visited.find(temp->left)==visited.end())
            {
                s.push(temp->left);
            }
            else if(temp->right!=NULL && visited.find(temp->right)==visited.end())
            {
                s.push(temp->right);
            }
            else
            {
                s.pop();
                visited.insert(temp);
                ans.push_back(temp->val);   
            }
        }
        return ans;
    }