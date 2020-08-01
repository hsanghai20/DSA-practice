// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

// solution: (recursion)
void inorder(TreeNode* root,vector<int>& ans)
    {
        if(root==NULL)
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // recursive approach
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }

// solution: (iterative)
vector<int> inorderTraversal(TreeNode* root) {
        // interative approach
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* temp=root;
        while(temp!=NULL || !s.empty())
        {
            while(temp!=NULL)
            {
                s.push(temp);
                temp=temp->left;
            }
            temp=s.top();
            s.pop();
            ans.push_back(temp->val);
            temp=temp->right;
        }
        return ans;
    }