// Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

// solution:(recursive)
void preorder(TreeNode* root,vector<int>& ans)
    {
        if(root==NULL)
            return;
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }

// solution: (iterative)
 vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* temp=root;
        while(temp!=NULL || !s.empty())
        {
            while(temp!=NULL)
            {
                ans.push_back(temp->val);
                s.push(temp);
                temp=temp->left;
            }
            temp=s.top();
            s.pop();
            temp=temp->right;
        }
        return ans;
    }